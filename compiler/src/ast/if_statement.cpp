#include "if_statement.h"
#include <llvm/IR/BasicBlock.h>
#include "node.h"
#include "context.h"
#include <vector>

namespace fluster { namespace ast {

//// Methods

void
IfStatement::
commit(db::ProgramDatabase& db) const
{
    cond->commit(db);
    then->commit(db);
    else_->commit(db);
}


llvm::Value*
IfStatement::
generateCode(GenerationContext& ctx) const
{
    const auto cond_val = cond->generateCode(ctx);
    std::vector<llvm::Value*> truth_op_args = {cond_val};
    // invoke the truth operation for that type
    // XXX: blows up on failed find which is a nullptr
    // use at?
    auto cond_truth = cond->result_type->db.operations.at("truth")->getLLVMRepr(ctx, truth_op_args);

    //compare to boolean true (integer 1)
    cond_truth = ctx.builder.CreateICmpEQ(
        cond_truth,
        llvm::ConstantInt::get(ctx.context, llvm::APInt(1, 1))
    );

    auto owner = ctx.builder.GetInsertBlock()->getParent();

    auto then_block = llvm::BasicBlock::Create(ctx.context, "then_block", owner);
    auto else_block = llvm::BasicBlock::Create(ctx.context, "else_block", owner);
    auto join_block = llvm::BasicBlock::Create(ctx.context, "continue", owner);
                
    ctx.builder.CreateCondBr(cond_truth, then_block, else_block);

    // populate 'then' block
    ctx.builder.SetInsertPoint(then_block);
    auto then_val = then->generateCode(ctx);
    ctx.builder.CreateBr(join_block);
    then_block = ctx.builder.GetInsertBlock();

    // populate 'else' block
    owner->getBasicBlockList().push_back(else_block);
    ctx.builder.SetInsertPoint(else_block);  //emit then
    auto else_val = else_->generateCode(ctx);
    ctx.builder.CreateBr(join_block);
    else_block = ctx.builder.GetInsertBlock();

    // populate 'join' block
    owner->getBasicBlockList().push_back(join_block);
    ctx.builder.SetInsertPoint(join_block);
    llvm::PHINode* pn = ctx.builder.CreatePHI(llvm::Type::getDoubleTy(ctx.context), 2);
    pn->addIncoming(then_val, then_block);
    pn->addIncoming(else_val, else_block);

    return pn;
}


Node::Ptr
IfStatement::
empty()
{
    return IfStatement::Ptr::make().castUp<Node>();
}


void
IfStatement::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<if>" << std::endl;

    // XXX: debug this for preconditions
    if (cond) cond->print(os, indent_level+1);
    if (then) then->print(os, indent_level+1);
    if (else_) else_->print(os, indent_level+1);
    
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "</if>" << std::endl;
}

//// Construction

IfStatement::
IfStatement( Expr::Ptr in_cond
           , Node::Ptr in_then
           , Node::Ptr in_else
           )
    : cond(in_cond)
    , then(in_then)
    , else_(in_else)
{}



} }
