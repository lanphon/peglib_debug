#include "represent.h"
#include "testlang.h"

using namespace std;

peg::parser representation_t::g_parser;
std::string representation_t::g_syntax_error;
size_t representation_t::g_syntax_error_line = 0;
size_t representation_t::g_syntax_error_col = 0;


/**
 * @brief init the static global parser
 */
void representation_t::init()
{
    if ((bool)g_parser == true) return;

    std::string wgl_peg = R"(
ROOT        <- (word (NL word)*)?
        CR          <- '\r'
        LF          <- '\n'
        ~NL         <- CR LF / CR / LF
        )";

    g_parser = peg::parser{ wgl_peg.c_str() };
    g_parser.enable_ast();

    // record the error information here
    g_parser.log = [&](size_t ln, size_t col, const string& msg) {
        g_syntax_error_line = ln;
        g_syntax_error_col = col;
        g_syntax_error = msg;
    };
}
