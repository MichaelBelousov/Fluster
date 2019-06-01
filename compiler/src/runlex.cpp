
#include <iostream>
#include "lexer.gen.h"
#include "parser.gen.h"

// HACK: stole from bison output since it's all private
const char* const token_names[] =
{
    "END", "error", "$undefined", "SEQ_EXEC", "LIST", "ASSIGN", "LAMBDA",
    "TYPE_ASSERT", "DISJUNCT", "CONJUNCT", "IMPLY", "EQUALITY", "SPACESHIP",
    "RELATIONAL", "IN", "LSHIFT", "RSHIFT", "ADD", "SUB", "MULT", "DIV",
    "MOD", "POW", "ROOT", "COMPLEMENT", "NEGATE", "TYPE_MUT", "TYPE_ARRAY",
    "TYPE_PTR", "TYPE_REF", "TYPE_OPT", "IS", "HAS", "SQUARE_ROOT",
    "PREINCREMENT", "PREDECREMENT", "SPREAD", "CLONEOF", "TYPEOF", "IMPORT",
    "COMPOSE", "POSTINCREMENT", "POSTDECREMENT", "INVOKE", "SUBSCRIPT",
    "PARAMETRIZE", "ACCESS", "KW_IF", "KW_ELSE", "KW_ELIF", "KW_FOR",
    "KW_WHILE", "KW_UNTIL", "KW_REPEAT", "KW_CASE", "KW_TRY", "KW_RETRY",
    "KW_HANDLE", "KW_RAISE", "KW_WITH", "KW_STRUCT", "KW_CLASS", "INDENT",
    "OUTDENT", "NL", "SEMICOLON", "COMMA", "EQ", "PLUS_EQ", "DASH_EQ",
    "STAR_EQ", "FSLASH_EQ", "FSLASH_FSLASH_EQ", "CARET_FSLASH_EQ",
    "CARET_EQ", "AMPERSAND_EQ", "PIPE_EQ", "TILDE_EQ", "LANGLE_LANGLE_EQ",
    "RANGLE_RANGLE_EQ", "DASH_RANGLE_EQ", "EQ_RANGLE", "COLON", "PIPE",
    "AMPERSAND", "DASH_RANGLE", "EQ_EQ", "EXCLAIM_EQ", "HASH_EQ",
    "EXCLAIM_HASH_EQ", "LANGLE_EQ_RANGLE", "LANGLE", "LANGLE_EQ",
    "RANGLE_EQ", "RANGLE", "LANGLE_LANGLE", "RANGLE_RANGLE", "PLUS", "DASH",
    "STAR", "FSLASH", "FSLASH_FSLASH", "PERCENT", "CARET", "CARET_FSLASH",
    "DASH_DASH", "PLUS_PLUS", "TILDE", "EXCLAIM", "QUES", "DOT_DOT_DOT",
    "KW_CLONEOF", "KW_TYPEOF", "KW_IMPORT", "AT", "DOT", "LPAR", "RPAR",
    "LBRACK", "RBRACK", "LBRACE", "RBRACE", "Identifier", "IntegerLiteral",
    "FloatLiteral", "StringLiteral", "$accept", "program", "code", "line",
    "block", "statement", "expr", "lambda_body", "lambda_expr", "if",
    "if_follow_up", "commalist_", "commalist", "par_list", YY_NULLPTR
};

using yy::Lexer;

int main()
{
    std::ios::sync_with_stdio(false);

    Lexer lexer(std::cin);
    lexer.set_debug(false);

    while(true)
    {
        auto lexeme = lexer.lex();
        std::cout << lexeme.token() << ": " << token_names[lexeme.token()] << std::endl;
        if (lexeme.token() == yy::Parser::token::END) // != 0
            break;
    }

    return 0;
}
