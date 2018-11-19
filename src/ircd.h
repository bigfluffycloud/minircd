#if	!defined(__ircd_h)
#define	__ircd_h
#include <stdarg.h>

/////
/// There's some gross stuff here, will be replaced soon...
////
// proto: (void *)mem_alloc	((size_t)size, (const char*)pool_name)
//	OnError: ret=NULL, errno=set
#define	mem_alloc(x, y)		malloc((size_t)x)
// proto: (int)mem_free		((void *)ptr)
//	OnError: ret=-errno, errno=set
#define	mem_free(x)		free((void *)x)

// proto: (void)fatal		((const char*)msg, ...)
//	OnError: N/A	- Fatally ends the process
extern	void	fatal(const char *msg, ...);

#define	MAGIC_LIST	0xdeadbeef
#define	MAGIC_MODULE	0xc0ffee
#define	MAGIC_USER	0xdeadd00d
#define	MAGIC_CHANNEL	0xbadd00d

struct List {
   long magic;
};
typedef struct List List;

extern List *list_init(void);

#endif	// !defined(__ircd_h)
