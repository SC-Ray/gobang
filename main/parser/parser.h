#pragma once

/**
 * @brief parse command line arguments.
 * @param argument_count the count of argument.
 * @param argument_value the value of argument.
 * @return return the size of chessboard if argument is correct.
 *         return -1 if the count of argument is incorrect.
 *         return -2 if the value of argument is incorrect.
 * @version 1.0
 * @date 2024/9/17
 * @author ProYRB
 */
int parse_argument(const int argument_count, char *const argument_value[]);
