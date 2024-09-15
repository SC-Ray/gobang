#include "chessboard.h"
#include "debug.h"
#include "main.h"

#include <stdlib.h>

/**
 * @brief the enum type of unit in chessboard.
 */
typedef enum _chessboard_unit_man
{
    Null = 0,
    White,
    Black,
} chessboard_unit_man;

/**
 * @brief the coord of unit in chessboard.
 */
typedef struct _chessboard_unit_coord
{
    unsigned char x;
    unsigned char y;
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
    chessboard_unit_man man;
    chessboard_unit_coord coord;
    chessboard_unit_symbol symbol;
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

char chessboard_initialize(const unsigned char size)
{
    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard initializing");

    // the size can not be bigger than 32
    if (size > 32)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard size is out of range 5-32");
        return -1;
    }

    // the chessboard chessboard has been initialized
    if (NULL != chessboard.data)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard has been initialized");
        return -2;
    }

    // malloc the chessboard in the bytes
    chessboard.data = malloc(chessboard.size = (size * size * sizeof(chessboard_unit)));

    // initialization failed
    if (NULL == chessboard.data)
    {
        LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard initialization failed");
        return -3;
    }

    LOG_MESSAGE("[%s: %d] %s\n", GET_FILE_NAME(__FILE__), __LINE__, "chessboard initialize successfully");
    return 0; // initialize successfully
}

void chessboard_print(void)
{
    printf("┌ 0───1───2───x\n");
    printf("0 ┌───┬───┐\n");
    printf("| |   |   |\n");
    printf("1 └───┼───┘\n");
    printf("|\n");
    printf("y\n");
}
