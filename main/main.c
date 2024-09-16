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

    int y;
    int x;
    int man;
    chessboard_print();
    scanf("%d %d %d", &y, &x, &man);
    chessboard_set_unit(y, x, man);
    chessboard_print();
    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "print");

    while (0 != chessboard_determine(y, x))
    {
        scanf("%d %d %d", &y, &x, &man);
        chessboard_set_unit(y, x, man);
        chessboard_print();
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "print");
    }

    return 0;
}
