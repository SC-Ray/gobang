#include "chessboard_class_private.h"
#include "debug.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief whether enable debug for this file if have enable debug.
 */
#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG               1

/**
 * @brief the min size of chessboard.
 */
#define CHESSBOARD_MIN_SIZE 5

/**
 * @brief the max size of chessboard.
 */
#define CHESSBOARD_MAX_SIZE 32

/**
 * @brief the length of template char array.
 */
#define TEMPLATE_LENGTH     ((CHESSBOARD_MAX_SIZE - 1) * 4 + 1)

/**
 * @brief the static chessboard.
 */
static struct _chessboard_object chessboard = {NULL, 0};

char chessboard_initialize_data(const int size)
{
    if (size < CHESSBOARD_MIN_SIZE || size > CHESSBOARD_MAX_SIZE)
    {
        LOG_MESSAGE("[%s:%d] %s([%d-%d])\n", EXTRACT_NAME(__FILE__), __LINE__,
                    "the size of chessboard is out of range", CHESSBOARD_MIN_SIZE,
                    CHESSBOARD_MAX_SIZE);
        return -1;
    }

    if (NULL != chessboard.data)
    {
        LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__,
                    "the chessboard has been initialized");
        return -2;
    }

    chessboard.data = malloc(sizeof(struct _chessboard_unit *) * size);
    if (NULL == chessboard.data)
    {
        LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__, "malloc failed");
        return -3;
    }
    for (unsigned char index_y = 0; index_y < size; ++index_y)
    {
        chessboard.data[index_y] = malloc(sizeof(struct _chessboard_unit) * size);
        if (NULL == chessboard.data[index_y])
        {
            LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__, "malloc failed");
            return -3;
        }
    }

    for (unsigned char index_y = 0; index_y < size; ++index_y)
    {
        for (unsigned char index_x = 0; index_x < size; ++index_x)
        {
            chessboard.data[index_y][index_x].coord.y = index_y;
            chessboard.data[index_y][index_x].coord.x = index_x;
            chessboard.data[index_y][index_x].man = Null;
        }
    }
    chessboard.size = size;

    LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__,
                "chessboard initialize successfully");
    return 0;
}

void chessboard_print()
{
    static char template[TEMPLATE_LENGTH];

    printf(" ┌─");
    for (unsigned char index_x = 0; index_x < chessboard.size; ++index_x)
    {
        printf("%-4d", index_x);
    }
    printf("\bx\n");

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
            printf("%2d ", index_y / 2);
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
    printf(" y\n");
}

void chessboard_initialize_coord(struct _chessboard_unit_coord *const coord)
{
    coord->y = coord->x = -1;
}

char chessboard_judge_range(const struct _chessboard_unit_coord *const coord)
{
    char return_value = 0;
    if (coord->y < 0 || coord->y > (chessboard.size - 1))
    {
        LOG_MESSAGE("[%s:%d] %d %s([%d-%d])\n", EXTRACT_NAME(__FILE__), __LINE__, coord->y,
                    "is out of range", 0, CHESSBOARD_MAX_SIZE - 1);
        return_value -= 1;
    }
    if (coord->x < 0 || coord->x > (chessboard.size - 1))
    {
        LOG_MESSAGE("[%s:%d] %d %s([%d-%d])\n", EXTRACT_NAME(__FILE__), __LINE__, coord->x,
                    "is out of range", 0, CHESSBOARD_MAX_SIZE - 1);
        return_value -= 2;
    }
    return return_value;
}

enum _chessboard_unit_man chessboard_get_unit_man(const struct _chessboard_unit_coord *const coord)
{
    if (0 != chessboard_judge_range(coord))
    {
        return -1;
    }
    return chessboard.data[coord->y][coord->x].man;
}

char chessboard_set_unit(const struct _chessboard_unit_coord *const coord,
                         const enum _chessboard_unit_man man)
{
    if (0 != chessboard_judge_range(coord))
    {
        return -1;
    }

    if (chessboard_get_unit_man(coord) == Null)
    {
        chessboard.data[coord->y][coord->x].man = man;
        return 0;
    }
    else if (chessboard_get_unit_man(coord) == man)
    {
        return -2;
    }
    else
    {
        return -3;
    }
}

char chessboard_determine(const struct _chessboard_unit_coord *const coord)
{
    if (0 != chessboard_judge_range(coord))
    {
        return -1;
    }

    if (Null == chessboard_get_unit_man(coord))
    {
        return -2;
    }

    const enum _chessboard_unit_man base_man = chessboard_get_unit_man(coord);

    /* '\' */
    LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__, "'\\' model");
    int count = 1;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y - index, coord->x - index};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
    }
    for (unsigned char index = 1; index < 5; ++index)
    {
        if (5 == count)
            return 0;
        struct _chessboard_unit_coord new_coord = {coord->y + index, coord->x + index};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
    }

    /* '/' */
    LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__, "'/' model");
    count = 1;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y - index, coord->x + index};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
    }
    if (count > 4)
        return 0;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y + index, coord->x - index};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
        if (count > 4)
            return 0;
    }

    /* '─' */
    LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__, "'─' model");
    count = 1;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y, coord->x - index};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
    }
    if (count > 4)
        return 0;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y, coord->x + index};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
        if (count > 4)
            return 0;
    }

    /* '|' */
    LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__, "'|' model");
    count = 1;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y - index, coord->x};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
    }
    if (count > 4)
        return 0;
    for (unsigned char index = 1; index < 5; ++index)
    {
        struct _chessboard_unit_coord new_coord = {coord->y + index, coord->x};
        if (0 != chessboard_judge_range(&new_coord))
            break;
        if (chessboard_get_unit_man(&new_coord) == base_man)
        {
            ++count;
            LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "count:", count);
        }
        else
            break;
        if (count > 4)
            return 0;
    }

    return -3;
}
