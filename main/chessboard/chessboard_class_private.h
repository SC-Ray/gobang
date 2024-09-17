#pragma once

enum _chessboard_unit_man
{
    /* null man. */
    Null = 0,

    /* white man. */
    White,

    /* black man. */
    Black,
};

struct _chessboard_unit_coord
{
    /* the y coord. */
    int y;

    /* the x coord. */
    int x;
};

struct _chessboard_unit
{
    /* the coord of unit. */
    struct _chessboard_unit_coord coord;

    /* the enum of man. */
    enum _chessboard_unit_man man;
};

struct _chessboard_object
{
    /* the pointer to two-dimensional array. */
    struct _chessboard_unit **data;

    /* the size of the chessboard. */
    int size;
};
