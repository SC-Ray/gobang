#include "parser.h"

#include <stdlib.h>

unsigned char parse_cmdline_arguments(const int argument_count, char *const argument_value[]) { return atoi(argument_value[1]); }
