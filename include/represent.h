#ifndef PUASM_REPRESENTATION_HEADER__
#define PUASM_REPRESENTATION_HEADER__

#include <ostream>
#include <string_view>
#include <string>
#include <vector>
#include <list>
#include "peglib.h"
#include "testlang.h"

class representation_t
{
    public:

        representation_t() { init(); }
        ~representation_t() {}

        void init();
    private:
        // global status, to receive the parser's output
        static peg::parser g_parser;
        static std::string g_syntax_error;
        static size_t g_syntax_error_line;
        static size_t g_syntax_error_col;

};

#endif
