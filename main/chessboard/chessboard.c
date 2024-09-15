#include "chessboard.h"

#include <malloc.h>
#include <stdio.h>

struct _chessboard_unit
{
    int value;
};

static chessboard_object chessboard = NULL;

chessboard_object chessboard_initialize(const unsigned char size)
{
    printf("chessboard pointer: %p\n", chessboard);
    size_t bytes;
    chessboard = malloc(bytes = (size * size * sizeof(chessboard_unit)));
    printf("chessboard pointer: %p\tbytes:%ld\n", chessboard, bytes);
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
