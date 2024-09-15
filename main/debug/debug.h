#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <string.h>

#define GET_FILE_NAME(x) (strrchr(x, '/') ? strrchr(x, '/') + 1 : x)
#define LOG_MESSAGE(format, ...)                                                                                                                     \
    while (DEBUG)                                                                                                                                    \
    {                                                                                                                                                \
        printf(format, __VA_ARGS__);                                                                                                                 \
        break;                                                                                                                                       \
    }

#endif /* DEBUG_H */