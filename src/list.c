#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ircd.h"

List	*list_init(void) {
   List *lp = NULL;

   if ((lp = mem_alloc(sizeof(List), "core:List")) == NULL)
      fatal("list_init: cannot continue. mem_alloc failed (see syslog)");

   memset((void *)&lp, (int)0, sizeof(List));
   lp->magic = MAGIC_LIST;

   return lp;
}
