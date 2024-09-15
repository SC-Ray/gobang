#include "main.h"
#include "chessboard.h"
#include "debug.h"
#include "parser.h"

int main(const int argument_count, char *const argument_value[])
{
    // get the size from parser
    unsigned char size = parse_cmdline_arguments(argument_count, argument_value);

    // chessboard initialize
    chessboard_initialize(size);
    chessboard_print();

    return 0;
}
