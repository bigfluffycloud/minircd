#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "ircd.h"
#include "module.h"
#include "parser.h"

int	main(int argc, char **argv) {
    printf("minircd %s starting up....\n", VERSION);
    return 0;
}

// Log a fatal error and abort()
void    fatal(const char *msg, ...) {
    va_list va;
    va_start(va, msg);
    abort();
}

