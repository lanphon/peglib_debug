#include "peglib.h"
#include <stdexcept>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "testlang.h"
#include "represent.h"

using namespace std;

static representation_t _as;

uint32_t puasm_init()
{
    _as.init();
    return 0;
}

uint32_t puasm_deinit()
{
    return 0;
}
