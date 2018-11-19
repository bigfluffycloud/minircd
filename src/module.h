#if	!defined(__module_h)
#define	__module_h
#include "parser.h"

struct	module {
    int	refcnt;			// Reference count
};

typedef	struct module	Module;

// Load a module, optionally with restricted symbol visibility
extern	Module *mod_load(const char *path, int restricted);
extern	int	mod_unload(Module *module);
// get mod handle - name is basename of path (ex: m_whois.so)
extern	Module *mod_find(const char *name);

#endif	// !defined(__module_h)
