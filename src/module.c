#include <stdlib.h>
#include <sys/types.h>
#include <dlfcn.h>
#include "ircd.h"
#include "module.h"

List	*Modules = NULL;
/*
 * mod_init(void): Initialize module sub-system
 */
int	mod_init(void) {
    if ((Modules = list_init()) == NULL)
       fatal("mod_init: list init failed");

    return 0;
}

Module *mod_load(const char *path, int restricted) {
    Module *mod = NULL;

    if ((mod = mem_alloc(sizeof(Module), "core:Module")) == NULL)
       fatal("mod_load cannot continue. mem_alloc error (see syslog)");

    return mod;
}
