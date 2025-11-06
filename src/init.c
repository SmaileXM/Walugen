#include "base/parser.h"

int main(int argc, char** argv)
{
    if (parser(argc, argv) != 0)
        return 1;

    if (validation() != 0)
        return 1;
    
    return 0;
}