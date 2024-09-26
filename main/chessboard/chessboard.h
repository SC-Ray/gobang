#pragma once

#include "chessboard_class.h"
#include "chessboard_class_private.h"

/**
 * @brief initialize the chessboard.
 * @param size the size of chessboard.
 * @return return 0 if done successfully.
 *         return -1 if the size is out of range.
 *         return -2 if the chessboard has been initialized.
 *         return -3 if malloc failed.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
char chessboard_initialize_data(const int size);

/**
 * @brief print the chessboad.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
void chessboard_print();

/**
 * @brief initialize the coord.
 * @param coord the coord of unit.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
void chessboard_initialize_coord(chessboard_unit_coord *const coord);

/**
 * @brief judge the coord whether is in range.
 * @param coord the coord of unit.
 * @return return 0 if the coord is in range.
 *         return -1 if the y of the coord is out of range.
 *         return -2 if the x of the coord is out of range.
 *         return -3 if the y and x of the coord are out of range.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
char chessboard_judge_range(const chessboard_unit_coord *const coord);

/**
 * @brief get the man of unit.
 * @param coord the coord of unit.
 * @return return the enum value if done successfully.
 *         return -1 if the coord is out of range.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
chessboard_unit_man chessboard_get_unit_man(const chessboard_unit_coord *const coord);

/**
 * @brief set the man of unit.
 * @param coord the coord of unit.
 * @param man the enum you want to be set.
 * @return return 0 if done successfully.
 *         return -1 if the coord is out of range.
 *         return -2 if the unit has the same man.
 *         return -3 if the unit has the another man.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
char chessboard_set_unit(const chessboard_unit_coord *const coord, const chessboard_unit_man man);

/**
 * @brief determine chessboard.
 * @param coord the coord of unit.
 * @return return 0 if have a victory.
 *         return -1 if the coord is out of range.
 *         return -2 if this is Null.
 *         return -3 if do not have a victory.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
char chessboard_determine(const chessboard_unit_coord *const coord);

/**
 * @brief record location of chess
 * @param coord the coord of unit.
 * @param man the enum you want to be set.
 */
void record_move(const struct _chessboard_unit_coord *coord, enum _chessboard_unit_man man)