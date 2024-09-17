#pragma once

/**
 * @brief the enum of man.
 * @param Null null man.
 * @param White white man.
 * @param Black black man.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
typedef enum _chessboard_unit_man chessboard_unit_man;

/**
 * @brief the coord of unit.
 * @param y the y coord.
 * @param x the x coord.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
typedef struct _chessboard_unit_coord chessboard_unit_coord;

/**
 * @brief the unit of chessboard.
 * @param coord the coord of unit.
 * @param man the enum of man.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
typedef struct _chessboard_unit chessboard_unit;

/**
 * @brief the chessboard.
 * @param data the pointer to two-dimensional array.
 * @param size the size of the chessboard.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
typedef struct _chessboard_object chessboard_object;
