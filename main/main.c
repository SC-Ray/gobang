#include "main.h"
#include "chessboard.h"
#include "debug.h"
#include "parser.h"

int main(const int argument_count, char *const argument_value[])
{
    int size = parse_argument(argument_count, argument_value);

    char control_state = 0, return_state = 0;
    do
    {
        switch (chessboard_initialize_data(size))
        {
        case 0:
        {
            control_state = 0;
            break;
        }
        case -1:
        {
            printf("input new size:");
            scanf("%d", &size);
            control_state = 1;
            break;
        }
        case -2:
        {
            control_state = 0;
            break;
        }
        case -3:
        {
            control_state = 0;
            return_state = -1;
            break;
        }
        }
    }
    while (0 != control_state);

    if (return_state < 0)
    {
        return return_state;
    }

    unsigned int player_count = 0;
    chessboard_unit_coord player_iniput_coord;
    do
    {
        ++player_count;
        chessboard_print();
        char set_result = 0;
        do
        {
            chessboard_initialize_coord(&player_iniput_coord);
            printf("%s player(y, x):", (0 == player_count % 2) ? "balck" : "white");
            scanf("%d %d", &(player_iniput_coord.y), &(player_iniput_coord.x));
            switch (set_result = chessboard_set_unit(&player_iniput_coord,
                                                     (0 == player_count % 2) ? Black : White))
            {
            case 0:
            {
                break;
            }
            case -1:
            {
                printf("your input is out of range\n");
                break;
            }
            default:
            {
                printf("there is a man\n");
                break;
            }
            }
        }
        while (0 != set_result);
    }
    while (0 != chessboard_determine(&player_iniput_coord));

    chessboard_print();
    printf("%s player have a victory!\n", (0 == player_count % 2) ? "balck" : "white");

    return 0;
}
