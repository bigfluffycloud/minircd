#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <string.h>
#include "ircd.h"
#include "module.h"
#include "parser.h"

struct	irc_msg {
    char sender[