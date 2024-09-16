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
    int round;
    chessboard_print();
    printf("Please ask the while side to play chess\n");
    printf("(y x 1)\n");
    scanf("%d %d %d", &y, &x, &man);
    chessboard_set_unit(y, x, man);
    chessboard_print();
    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "print");

    while (0 != chessboard_determine(y, x))
    {
        for (round = 1; round < size * size; ++round)
        {
            if (1 == round % 2)
            {
                printf("turn to black side play chess\n");
                printf("(y x 2)\n");
                scanf("%d %d %d", &y, &x, &man);
                if (y > size || x > size)
                {
                    printf("You have exceeded the maximum range,please print again!\n");
                    scanf("%d %d %d", &y, &x, &man);
                    chessboard_set_unit(y, x, man);
                    chessboard_print();
                }
                else
                {
                    chessboard_set_unit(y, x, man);
                    chessboard_print();
                }
            }

            if (0 == round % 2)
            {
                printf("turn to while side play chess\n");
                printf("(y x 1)\n");
                scanf("%d %d %d", &y, &x, &man);
                if (y > size || x > size)
                {
                    printf("You have exceeded the maximum range,please print again!\n");
                    scanf("%d %d %d", &y, &x, &man);
                    chessboard_set_unit(y, x, man);
                    chessboard_print();
                }
                else
                {
                    chessboard_set_unit(y, x, man);
                    chessboard_print();
                }
            }
        }

        // LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "print");
    }

    return 0;
}
