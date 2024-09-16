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
    for (unsigned char index_y = 0; index_y < size; ++index_y)
    {
        for (unsigned char index_x = 0; index_x < size; ++index_x)
        {
            chessboard_set_unit(index_y, index_x, Null);
        }
    }
    chessboard_print();
    chessboard_set_unit(0, 0, White);
    chessboard_set_unit(1, 1, White);
    chessboard_set_unit(2, 2, White);
    chessboard_set_unit(3, 3, White);
    chessboard_set_unit(4, 4, White);

    chessboard_print();
    int result = chessboard_determine(4, 4);
    LOG_MESSAGE("[%s: %d] %s: %d\n", GET_FILE_NAME(__FILE__), __LINE__, "result", result);
    if (0 == result)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "victory");
    }

    return 0;
}
