#include "parser.h"
#include "debug.h"
#include "main.h"

#include <stdlib.h>

unsigned char parse_cmdline_arguments(const int argument_count, char *const argument_value[])
{
    unsigned char size = atoi(argument_value[1]);
    LOG_MESSAGE("[%s: %d] %s: %d\n", GET_FILE_NAME(__FILE__), __LINE__, "the size of chessboard", size);
    return size;
}
