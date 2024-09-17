#include "parser.h"
#include "debug.h"
#include "main.h"

#include <stdlib.h>

/**
 * @brief whether enable debug for this file if have enable debug.
 */
#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG 1

int parse_argument(const int argument_count, char *const argument_value[])
{
    if (argument_count != 2)
    {
        LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__,
                    "the count of argument is incorrect");
        return -1;
    }

    int size = atoi(argument_value[1]);
    if (0 == size)
    {
        LOG_MESSAGE("[%s:%d] %s\n", EXTRACT_NAME(__FILE__), __LINE__,
                    "the value of argument is incorrect");
        return -2;
    }

    LOG_MESSAGE("[%s:%d] %s %d\n", EXTRACT_NAME(__FILE__), __LINE__, "the value of argument is",
                size);
    return size;
}
