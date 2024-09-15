#ifndef _CHESSBOARD_
#define _CHESSBOARD_

typedef struct _chessboard_unit chessboard_unit;

typedef chessboard_unit **chessboard_object;

/**
 * @brief malloc the size of chessboard
 * @return the pointer of chessboad
 */
chessboard_object chessboard_initialize(const unsigned char size);

/**
 * @brief print chessboad
 */
void chessboard_print(void);

#endif /*_CHESSBOARD_*/
