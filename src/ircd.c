#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ev.h>
#include "ircd.h"
#include "module.h"
#include "parser.h"

int dying = 0;

int	main(int argc, char **argv) {
    EV_P = ev_default_loop(0);
    printf("minircd %s starting up....\n", VERSION);
    // Read configuration
    // Start listeners
    // Main Loop
    parse_message(":joseph!webirc@irc.user PRIVMSG web37 :Hey dude what's up?");

    while (!dying) {
        // Process events
        ev_loop(EV_A_ 0);
    }
    return EXIT_SUCCESS;
}

// Log a fatal error and abort()
void    fatal(const char *msg, ...) {
    va_list va;
    va_start(va, msg);
    dying = 1;
    abort();
}
