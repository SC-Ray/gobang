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
            scanf("%d %d %d", &y, &x, &man);
            if (y > size - 1 || x > size - 1)
            {
                printf("You have exceeded the maximum range,please print again!\n");
                scanf("%d %d %d", &y, &x, &man);
                chessboard_set_unit(y, x, man);
            }
            else
            {
                chessboard_set_unit(y, x, man);
            }
        }
        else
        {
            printf("turn to while side play chess\n");
            printf("(y x 1)\n");
            scanf("%d %d %d", &y, &x, &man);
            if (y > size - 1 || x > size - 1)
            {
                printf("You have exceeded the maximum range,please print again!\n");
                scanf("%d %d %d", &y, &x, &man);
                chessboard_set_unit(y, x, man);
            }
            else
            {
                chessboard_set_unit(y, x, man);
            }
        }
    }

    return 0;
}
