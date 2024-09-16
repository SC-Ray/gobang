#pragma once

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
 * @brief malloc the size of chessboard.
 * @return return -1 if the size is bigger than 32.
 * @return return -2 if the chessboard has been initialized.
 * @return return -3 if initialization failed.
 * @return return 0 if initialize successfully.
 */
int chessboard_initialize(const unsigned char size);

/**
 * @brief print chessboad.
 */
void chessboard_print();

/**
 * @brief set the unit of chessboard.
 */
void chessboard_set_unit(const unsigned char y, const unsigned char x, const chessboard_unit_man man);

/**
 * @brief check chessboard to determine whether the conditions for victory.
 * @return return -2 if no victory.
 * @return return -1 if the positon is empty.
 * @return return 0 if victory.
 */
int chessboard_determine(const unsigned char y, const unsigned char x);
