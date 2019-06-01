#include <iostream>
#include <unordered_map>
#include "lexer.gen.h"
#include "parser.gen.h"

// HACK: stole from bison output since it's all private
// TODO: use cog or something to generate this list
const
std::unordered_map< yy::Parser::token::yytokentype
                  , const char*
                  >
    token_names =
{
    {yy::Parser::token::END, "END"},
    {yy::Parser::token::SEQ_EXEC, "SEQ_EXEC"},
    {yy::Parser::token::LIST, "LIST"},
    {yy::Parser::token::ASSIGN, "ASSIGN"},
    {yy::Parser::token::LAMBDA, "LAMBDA"},
    {yy::Parser::token::TYPE_ASSERT, "TYPE_ASSERT"},
    {yy::Parser::token::DISJUNCT, "DISJUNCT"},
    {yy::Parser::token::CONJUNCT, "CONJUNCT"},
    {yy::Parser::token::IMPLY, "IMPLY"},
    {yy::Parser::token::EQUALITY, "EQUALITY"},
    {yy::Parser::token::SPACESHIP, "SPACESHIP"},
    {yy::Parser::token::RELATIONAL, "RELATIONAL"},
    {yy::Parser::token::IN, "IN"},
    {yy::Parser::token::LSHIFT, "LSHIFT"},
    {yy::Parser::token::RSHIFT, "RSHIFT"},
    {yy::Parser::token::ADD, "ADD"},
    {yy::Parser::token::SUB, "SUB"},
    {yy::Parser::token::MULT, "MULT"},
    {yy::Parser::token::DIV, "DIV"},
    {yy::Parser::token::MOD, "MOD"},
    {yy::Parser::token::POW, "POW"},
    {yy::Parser::token::ROOT, "ROOT"},
    {yy::Parser::token::COMPLEMENT, "COMPLEMENT"},
    {yy::Parser::token::NEGATE, "NEGATE"},
    {yy::Parser::token::TYPE_MUT, "TYPE_MUT"},
    {yy::Parser::token::TYPE_ARRAY, "TYPE_ARRAY"},
    {yy::Parser::token::TYPE_PTR, "TYPE_PTR"},
    {yy::Parser::token::TYPE_REF, "TYPE_REF"},
    {yy::Parser::token::TYPE_OPT, "TYPE_OPT"},
    {yy::Parser::token::IS, "IS"},
    {yy::Parser::token::HAS, "HAS"},
    {yy::Parser::token::SQUARE_ROOT, "SQUARE_ROOT"},
    {yy::Parser::token::PREINCREMENT, "PREINCREMENT"},
    {yy::Parser::token::PREDECREMENT, "PREDECREMENT"},
    {yy::Parser::token::SPREAD, "SPREAD"},
    {yy::Parser::token::CLONEOF, "CLONEOF"},
    {yy::Parser::token::TYPEOF, "TYPEOF"},
    {yy::Parser::token::IMPORT, "IMPORT"},
    {yy::Parser::token::COMPOSE, "COMPOSE"},
    {yy::Parser::token::POSTINCREMENT, "POSTINCREMENT"},
    {yy::Parser::token::POSTDECREMENT, "POSTDECREMENT"},
    {yy::Parser::token::INVOKE, "INVOKE"},
    {yy::Parser::token::SUBSCRIPT, "SUBSCRIPT"},
    {yy::Parser::token::PARAMETRIZE, "PARAMETRIZE"},
    {yy::Parser::token::ACCESS, "ACCESS"},
    {yy::Parser::token::KW_IF, "KW_IF"},
    {yy::Parser::token::KW_ELSE, "KW_ELSE"},
    {yy::Parser::token::KW_ELIF, "KW_ELIF"},
    {yy::Parser::token::KW_FOR, "KW_FOR"},
    {yy::Parser::token::KW_WHILE, "KW_WHILE"},
    {yy::Parser::token::KW_UNTIL, "KW_UNTIL"},
    {yy::Parser::token::KW_REPEAT, "KW_REPEAT"},
    {yy::Parser::token::KW_CASE, "KW_CASE"},
    {yy::Parser::token::KW_TRY, "KW_TRY"},
    {yy::Parser::token::KW_RETRY, "KW_RETRY"},
    {yy::Parser::token::KW_HANDLE, "KW_HANDLE"},
    {yy::Parser::token::KW_RAISE, "KW_RAISE"},
    {yy::Parser::token::KW_WITH, "KW_WITH"},
    {yy::Parser::token::KW_STRUCT, "KW_STRUCT"},
    {yy::Parser::token::KW_CLASS, "KW_CLASS"},
    {yy::Parser::token::INDENT, "INDENT"},
    {yy::Parser::token::OUTDENT, "OUTDENT"},
    {yy::Parser::token::NL, "NL"},
    {yy::Parser::token::SEMICOLON, "SEMICOLON"},
    {yy::Parser::token::COMMA, "COMMA"},
    {yy::Parser::token::EQ, "EQ"},
    {yy::Parser::token::PLUS_EQ, "PLUS_EQ"},
    {yy::Parser::token::DASH_EQ, "DASH_EQ"},
    {yy::Parser::token::STAR_EQ, "STAR_EQ"},
    {yy::Parser::token::FSLASH_EQ, "FSLASH_EQ"},
    {yy::Parser::token::FSLASH_FSLASH_EQ, "FSLASH_FSLASH_EQ"},
    {yy::Parser::token::CARET_FSLASH_EQ, "CARET_FSLASH_EQ"},
    {yy::Parser::token::CARET_EQ, "CARET_EQ"},
    {yy::Parser::token::AMPERSAND_EQ, "AMPERSAND_EQ"},
    {yy::Parser::token::PIPE_EQ, "PIPE_EQ"},
    {yy::Parser::token::TILDE_EQ, "TILDE_EQ"},
    {yy::Parser::token::LANGLE_LANGLE_EQ, "LANGLE_LANGLE_EQ"},
    {yy::Parser::token::RANGLE_RANGLE_EQ, "RANGLE_RANGLE_EQ"},
    {yy::Parser::token::DASH_RANGLE_EQ, "DASH_RANGLE_EQ"},
    {yy::Parser::token::EQ_RANGLE, "EQ_RANGLE"},
    {yy::Parser::token::COLON, "COLON"},
    {yy::Parser::token::PIPE, "PIPE"},
    {yy::Parser::token::AMPERSAND, "AMPERSAND"},
    {yy::Parser::token::DASH_RANGLE, "DASH_RANGLE"},
    {yy::Parser::token::EQ_EQ, "EQ_EQ"},
    {yy::Parser::token::EXCLAIM_EQ, "EXCLAIM_EQ"},
    {yy::Parser::token::HASH_EQ, "HASH_EQ"},
    {yy::Parser::token::EXCLAIM_HASH_EQ, "EXCLAIM_HASH_EQ"},
    {yy::Parser::token::LANGLE_EQ_RANGLE, "LANGLE_EQ_RANGLE"},
    {yy::Parser::token::LANGLE, "LANGLE"},
    {yy::Parser::token::LANGLE_EQ, "LANGLE_EQ"},
    {yy::Parser::token::RANGLE_EQ, "RANGLE_EQ"},
    {yy::Parser::token::RANGLE, "RANGLE"},
    {yy::Parser::token::LANGLE_LANGLE, "LANGLE_LANGLE"},
    {yy::Parser::token::RANGLE_RANGLE, "RANGLE_RANGLE"},
    {yy::Parser::token::PLUS, "PLUS"},
    {yy::Parser::token::DASH, "DASH"},
    {yy::Parser::token::STAR, "STAR"},
    {yy::Parser::token::FSLASH, "FSLASH"},
    {yy::Parser::token::FSLASH_FSLASH, "FSLASH_FSLASH"},
    {yy::Parser::token::PERCENT, "PERCENT"},
    {yy::Parser::token::CARET, "CARET"},
    {yy::Parser::token::CARET_FSLASH, "CARET_FSLASH"},
    {yy::Parser::token::DASH_DASH, "DASH_DASH"},
    {yy::Parser::token::PLUS_PLUS, "PLUS_PLUS"},
    {yy::Parser::token::TILDE, "TILDE"},
    {yy::Parser::token::EXCLAIM, "EXCLAIM"},
    {yy::Parser::token::QUES, "QUES"},
    {yy::Parser::token::DOT_DOT_DOT, "DOT_DOT_DOT"},
    {yy::Parser::token::KW_CLONEOF, "KW_CLONEOF"},
    {yy::Parser::token::KW_TYPEOF, "KW_TYPEOF"},
    {yy::Parser::token::KW_IMPORT, "KW_IMPORT"},
    {yy::Parser::token::AT, "AT"},
    {yy::Parser::token::DOT, "DOT"},
    {yy::Parser::token::LPAR, "LPAR"},
    {yy::Parser::token::RPAR, "RPAR"},
    {yy::Parser::token::LBRACK, "LBRACK"},
    {yy::Parser::token::RBRACK, "RBRACK"},
    {yy::Parser::token::LBRACE, "LBRACE"},
    {yy::Parser::token::RBRACE, "RBRACE"},
    {yy::Parser::token::Identifier, "Identifier"},
    {yy::Parser::token::IntegerLiteral, "IntegerLiteral"},
    {yy::Parser::token::FloatLiteral, "FloatLiteral"},
    {yy::Parser::token::StringLiteral, "StringLiteral"}
};

using yy::Lexer;

int main()
{
    std::ios::sync_with_stdio(false);

    Lexer lexer(std::cin);
    //lexer.set_debug(false);

    while(true)
    {
        auto lexeme = lexer.get_token();
        std::cout << "@" << lexeme.location << ": "
                  << token_names.at(lexeme.token()) 
                  << std::endl;
        if (lexeme.token() == yy::Parser::token::END) // != 0
            break;
    }

    return 0;
}
