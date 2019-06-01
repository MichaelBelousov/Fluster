#include <iostream>
#include <unordered_map>
#include "lexer.gen.h"
#include "parser.gen.h"

// HACK: stole from bison output since it's all private
// TODO: use cog or something to generate this list
const
std::unordered_map< int //yy::Parser::token::yytokentype
                  , const char*
                  >
    token_names =
{
    {0, "END"},
    {258, "SEQ_EXEC"},
    {259, "LIST"},
    {260, "ASSIGN"},
    {261, "LAMBDA"},
    {262, "TYPE_ASSERT"},
    {263, "DISJUNCT"},
    {264, "CONJUNCT"},
    {265, "IMPLY"},
    {266, "EQUALITY"},
    {267, "SPACESHIP"},
    {268, "RELATIONAL"},
    {269, "IN"},
    {270, "LSHIFT"},
    {271, "RSHIFT"},
    {272, "ADD"},
    {273, "SUB"},
    {274, "MULT"},
    {275, "DIV"},
    {276, "MOD"},
    {277, "POW"},
    {278, "ROOT"},
    {279, "COMPLEMENT"},
    {280, "NEGATE"},
    {281, "TYPE_MUT"},
    {282, "TYPE_ARRAY"},
    {283, "TYPE_PTR"},
    {284, "TYPE_REF"},
    {285, "TYPE_OPT"},
    {286, "IS"},
    {287, "HAS"},
    {288, "SQUARE_ROOT"},
    {289, "PREINCREMENT"},
    {290, "PREDECREMENT"},
    {291, "SPREAD"},
    {292, "CLONEOF"},
    {293, "TYPEOF"},
    {294, "IMPORT"},
    {295, "COMPOSE"},
    {296, "POSTINCREMENT"},
    {297, "POSTDECREMENT"},
    {298, "INVOKE"},
    {299, "SUBSCRIPT"},
    {300, "PARAMETRIZE"},
    {301, "ACCESS"},
    {302, "KW_IF"},
    {303, "KW_ELSE"},
    {304, "KW_ELIF"},
    {305, "KW_FOR"},
    {306, "KW_WHILE"},
    {307, "KW_UNTIL"},
    {308, "KW_REPEAT"},
    {309, "KW_CASE"},
    {310, "KW_TRY"},
    {311, "KW_RETRY"},
    {312, "KW_HANDLE"},
    {313, "KW_RAISE"},
    {314, "KW_WITH"},
    {315, "KW_STRUCT"},
    {316, "KW_CLASS"},
    {317, "INDENT"},
    {318, "OUTDENT"},
    {319, "NL"},
    {320, "SEMICOLON"},
    {321, "COMMA"},
    {322, "EQ"},
    {323, "PLUS_EQ"},
    {324, "DASH_EQ"},
    {325, "STAR_EQ"},
    {326, "FSLASH_EQ"},
    {327, "FSLASH_FSLASH_EQ"},
    {328, "CARET_FSLASH_EQ"},
    {329, "CARET_EQ"},
    {330, "AMPERSAND_EQ"},
    {331, "PIPE_EQ"},
    {332, "TILDE_EQ"},
    {333, "LANGLE_LANGLE_EQ"},
    {334, "RANGLE_RANGLE_EQ"},
    {335, "DASH_RANGLE_EQ"},
    {336, "EQ_RANGLE"},
    {337, "COLON"},
    {338, "PIPE"},
    {339, "AMPERSAND"},
    {340, "DASH_RANGLE"},
    {341, "EQ_EQ"},
    {342, "EXCLAIM_EQ"},
    {343, "HASH_EQ"},
    {344, "EXCLAIM_HASH_EQ"},
    {345, "LANGLE_EQ_RANGLE"},
    {346, "LANGLE"},
    {347, "LANGLE_EQ"},
    {348, "RANGLE_EQ"},
    {349, "RANGLE"},
    {350, "LANGLE_LANGLE"},
    {351, "RANGLE_RANGLE"},
    {352, "PLUS"},
    {353, "DASH"},
    {354, "STAR"},
    {355, "FSLASH"},
    {356, "FSLASH_FSLASH"},
    {357, "PERCENT"},
    {358, "CARET"},
    {359, "CARET_FSLASH"},
    {360, "DASH_DASH"},
    {361, "PLUS_PLUS"},
    {362, "TILDE"},
    {363, "EXCLAIM"},
    {364, "QUES"},
    {365, "DOT_DOT_DOT"},
    {366, "KW_CLONEOF"},
    {367, "KW_TYPEOF"},
    {368, "KW_IMPORT"},
    {369, "AT"},
    {370, "DOT"},
    {371, "LPAR"},
    {372, "RPAR"},
    {373, "LBRACK"},
    {374, "RBRACK"},
    {375, "LBRACE"},
    {376, "RBRACE"},
    {377, "Identifier"},
    {378, "IntegerLiteral"},
    {379, "FloatLiteral"},
    {380, "StringLiteral"}
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
        std::cout << lexeme.token() << ": " << token_names.at(lexeme.token()) << std::endl;
        if (lexeme.token() == yy::Parser::token::END) // != 0
            break;
    }

    return 0;
}
