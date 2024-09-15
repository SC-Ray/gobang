#include "chessboard.h"
#include "parser.h"

#include <stdio.h>

int main(const int argument_count, char *const argument_value[])
{
    unsigned char size = parse_cmdline_arguments(argument_count, argument_value);
    printf("the size of chessboard: %d\n", size);

    chessboard_initialize(size);
    chessboard_print();

    return 0;
}
