
#define main COMPILER_MAIN
// definitely won't work since main is linked in
// definitely create a distinct entry point that can be called
// trivially

namespace if_statement_case_sources {

auto just_if =
R"(
if false
    ++a
)";

auto null_if =
R"(
if false
    pass
)";

auto complicated_condition =
R"(
if false
    pass
)";

auto if_block =
R"(
if false
    x += 5
    y: i32 = x
)";

auto just_else =
R"(
if false
    ++a
else
    ++b
)";

auto elif_chain =
R"(
if false
    ++a
elif
    ++b
elif
    ++c
else
    ++d
)";

auto elif_chain_no_else =
R"(
if false
    ++a
elif
    ++b
)";

auto nested_just_if =
R"(
if x
    if y & z
        a++
)";


auto just_if_with_bslash  =
R"(
if false \ ++a
)";

// XXX: do double back slashes work...? and the lexer needs to know
// to ignore them, no?
// e.g.: if cond \ class \ is hello

// XXX: lexer shouldn't emit an indent if an outdent is next
auto complicated_mixed  =
R"(
if x == 1
    ++a
    if y & z
        b++
    else
        if 5
            c--
elif x == 2 \ d += 2
else
    ++e
)";

}

int main(int argc, char* argv[])
{
    COMPILER_MAIN();
}
