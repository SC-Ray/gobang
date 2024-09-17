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

    for (unsigned int round = 0; round < size * size; ++round)
    {
        int y, x, man;
        chessboard_print();
        if (1 == round % 2)
        {
            printf("turn to black side play chess\n");
            printf("(y x 2)\n");

            while (1)
            {
                scanf("%d %d %d", &y, &x, &man);
                if (chessboard_judge_range == (1 << 1) | (1 << 0))
                {
                    printf("x and y is out of range,please input again!\n");

                    continue;
                }
                else if (chessboard_judge_range == (1 << 1))
                {
                    printf("x is out of range,please input again!\n");

                    continue;
                }
                else if (chessboard_judge_range == (1 << 0))
                {
                    printf("y is out of range,please input again!\n");

                    continue;
                }
                else if (chessboard_get_unit_man != 0)
                {
                    printf("There are chess pieces in this place\n");
                    continue;
                }
            }
            break;

            chessboard_set_unit(y, x, man);

            printf("%d\n", chessboard_get_unit_man(y, x));
        }
        else
        {
            printf("turn to while side play chess\n");
            printf("(y x 1)\n");
            while (1)
            {
                scanf("%d %d %d", &y, &x, &man);
                if (chessboard_judge_range == (1 << 1) | (1 << 0))
                {
                    printf("x and y is out of range,please input again!\n");

                    continue;
                }
                else if (chessboard_judge_range == (1 << 1))
                {
                    printf("x is out of range,please input again!\n");

                    continue;
                }
                else if (chessboard_judge_range == (1 << 0))
                {
                    printf("y is out of range,please input again!\n");

                    continue;
                }
                else if (chessboard_get_unit_man != 0)
                {
                    printf("There are chess pieces in this place\n");
                    continue;
                }
            }
            break;
            chessboard_set_unit(y, x, man);
            printf("%d\n", chessboard_get_unit_man(y, x));
        }
    }

    return 0;
}
