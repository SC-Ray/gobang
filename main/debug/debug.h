#pragma once

#include <stdio.h>
#include <string.h>

#define EXTRACT_NAME(origin) (strrchr(origin, '/') ? strrchr(origin, '/') + 1 : origin)
#define LOG_MESSAGE(format, ...)                                                                                                                     \
    while (DEBUG)                                                                                                                                    \
    {                                                                                                                                                \
        printf(format, __VA_ARGS__);                                                                                                                 \
        break;                                                                                                                                       \
    }
