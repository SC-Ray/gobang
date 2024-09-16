#include "chessboard.h"
#include "debug.h"
#include "main.h"

#include <stdlib.h>

#define CHESSBOARD_MAX_SIZE 32
#define TEMPLATE_LENGTH     (CHESSBOARD_MAX_SIZE - 1) * 4 + 1

/**
 * @brief the coord of unit in chessboard.
 */
typedef struct _chessboard_unit_coord
{
    unsigned char y;
    unsigned char x;
} chessboard_unit_coord;

/**
 * @brief the symbol of unit in chessboard.
 */
typedef char chessboard_unit_symbol;

/**
 * @brief the unit in chessboard.
 */
typedef struct _chessboard_unit
{
    chessboard_unit_coord coord;
    chessboard_unit_man man;
} chessboard_unit;

/**
 * @brief the object of chessboard.
 */
typedef struct _chessboard_object
{
    chessboard_unit **data;
    unsigned char size;
} chessboard_object;

/**
 * @brief the chessboard object.
 */
static chessboard_object chessboard;

int chessboard_initialize(const unsigned char size)
{
    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard initializing");

    // the size can not be bigger than CHESSBOARD_MAX_SIZE
    if (size > CHESSBOARD_MAX_SIZE)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard size is out of range 5-CHESSBOARD_MAX_SIZE");
        return -1;
    }

    // the chessboard chessboard has been initialized
    if (NULL != chessboard.data)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard has been initialized");
        return -2;
    }

    // malloc the chessboard
    chessboard.data = malloc(sizeof(chessboard_unit *) * size);
    if (NULL == chessboard.data)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard malloc failed");
        return -3;
    }
    for (unsigned char index = 0; index < size; ++index)
    {
        chessboard.data[index] = malloc(sizeof(chessboard_unit) * size);
        if (NULL == chessboard.data[index])
        {
            LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard malloc failed");
            return -3;
        }
    }
    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard malloc successfully");

    // data initialize
    for (unsigned char index_y = 0; index_y < size; ++index_y)
    {
        for (unsigned char index_x = 0; index_x < size; ++index_x)
        {
            LOG_MESSAGE("[%s: %d] %s y: %d x: %d\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard initialize", index_y, index_x);
            chessboard.data[index_y][index_x].coord.y = index_y;
            chessboard.data[index_y][index_x].coord.x = index_x;
            chessboard.data[index_y][index_x].man = Null;
        }
    }

    // size initialize
    chessboard.size = size;

    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard initialize successfully");
    return 0; // initialize successfully
}

void chessboard_print(void)
{
    char template[TEMPLATE_LENGTH] = "";
    printf("┌  ");
    for (unsigned char index_x = 0; index_x < chessboard.size; ++index_x)
    {
        printf("%-4d", index_x);
    }
    printf("x\n");
    for (unsigned char index_y = 0; index_y < (chessboard.size * 2 - 1); ++index_y)
    {
        if (1 == index_y % 2)
        {
            printf("   ");
            for (unsigned char index_x = 0; index_x < chessboard.size; ++index_x)
            {
                printf("|   ");
            }
            printf("\n");
        }
        else
        {
            memset(template, '\0', TEMPLATE_LENGTH);
            printf("%-2d ", index_y / 2);
            if (0 == index_y)
            {
                for (unsigned char index_x = 0; index_x < chessboard.size; ++index_x)
                {
                    if (0 == index_x)
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, "● ─");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, "○ ─");
                        }
                        break;
                        default:
                        {
                            strcat(template, "┌──");
                        }
                        break;
                        }
                    }
                    else if ((chessboard.size - 1) == index_x)
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, " ●");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, " ○");
                        }
                        break;
                        default:
                        {
                            strcat(template, "─┐");
                        }
                        break;
                        }
                    }
                    else
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, " ● ─");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, " ○ ─");
                        }
                        break;
                        default:
                        {
                            strcat(template, "─┬──");
                        }
                        break;
                        }
                    }
                }
                strcat(template, "\n");
            }
            else if ((chessboard.size - 1) == (index_y / 2))
            {
                for (unsigned char index_x = 0; index_x < chessboard.size; ++index_x)
                {
                    if (0 == index_x)
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, "● ─");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, "○ ─");
                        }
                        break;
                        default:
                        {
                            strcat(template, "└──");
                        }
                        break;
                        }
                    }
                    else if ((chessboard.size - 1) == index_x)
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, " ●");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, " ○");
                        }
                        break;
                        default:
                        {
                            strcat(template, "─┘");
                        }
                        break;
                        }
                    }
                    else
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, " ● ─");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, " ○ ─");
                        }
                        break;
                        default:
                        {
                            strcat(template, "─┴──");
                        }
                        break;
                        }
                    }
                }
                strcat(template, "\n");
            }
            else
            {
                for (unsigned char index_x = 0; index_x < chessboard.size; ++index_x)
                {
                    if (0 == index_x)
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, "● ─");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, "○ ─");
                        }
                        break;
                        default:
                        {
                            strcat(template, "├──");
                        }
                        break;
                        }
                    }
                    else if ((chessboard.size - 1) == index_x)
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, " ●");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, " ○");
                        }
                        break;
                        default:
                        {
                            strcat(template, "─┤");
                        }
                        break;
                        }
                    }
                    else
                    {
                        switch (chessboard.data[index_y / 2][index_x].man)
                        {
                        case White:
                        {
                            strcat(template, " ● ─");
                        }
                        break;
                        case Black:
                        {
                            strcat(template, " ○ ─");
                        }
                        break;
                        default:
                        {
                            strcat(template, "─┼──");
                        }
                        break;
                        }
                    }
                }
                strcat(template, "\n");
            }
            printf("%s", template);
        }
    }
    printf("y\n");
}

void chessboard_set_unit(const unsigned char y, const unsigned char x, const chessboard_unit_man man) { chessboard.data[y][x].man = man; }

int chessboard_determine(const unsigned char y, const unsigned char x)
{
    int i, j;
    for (i = 0; i < chessboard.size; ++i)
    {
        for (j = 0; j < chessboard.size; ++j)
        {
            if (chessboard.data[i][j].man = Null)
            {
                continue;
            }
        }
    }

    if (i < chessboard.size - 4)
    {
        if (chessboard.data[i][j].man == chessboard.data[i + 1][j].man && chessboard.data[i][j].man == chessboard.data[i + 2][j].man &&
            chessboard.data[i][j].man == chessboard.data[i + 3][j].man && chessboard.data[i][j].man == chessboard.data[i + 4][j].man &&
            chessboard.data[i][j].man == chessboard.data[i + 5][j].man)
        {
            return 0;
        }
    }

    if (j < chessboard.size - 4)
    {
        if (chessboard.data[i][j].man == chessboard.data[i][j + 1].man && chessboard.data[i][j].man == chessboard.data[i][j + 2].man &&
            chessboard.data[i][j].man == chessboard.data[i][j + 3].man && chessboard.data[i][j].man == chessboard.data[i][j + 4].man &&
            chessboard.data[i][j].man == chessboard.data[i][j + 5].man)
        {
            return 0;
        }
    }

    if (i < chessboard.size - 4 && j < chessboard.size - 4)
    {
        if (chessboard.data[i][j].man == chessboard.data[i + 1][j + 1].man && chessboard.data[i][j].man == chessboard.data[i + 2][j + 2].man &&
            chessboard.data[i][j].man == chessboard.data[i + 3][j + 3].man && chessboard.data[i][j].man == chessboard.data[i + 4][j + 4].man &&
            chessboard.data[i][j].man == chessboard.data[i + 5][j + 5].man)
        {
            return 0;
        }
    }

    if (i > 4, j < chessboard.size - 4)
    {
        if (chessboard.data[i][j].man == chessboard.data[i - 1][j + 1].man && chessboard.data[i][j].man == chessboard.data[i - 2][j + 2].man &&
            chessboard.data[i][j].man == chessboard.data[i - 3][j + 3].man && chessboard.data[i][j].man == chessboard.data[i - 4][j + 4].man &&
            chessboard.data[i][j].man == chessboard.data[i - 5][j + 5].man)
        {
            return 0;
        }
    }

    return Null;
}