MINIRCD_VERSION=0.0.1

all: world
CFLAGS := -Wall -ansi -pedantic -std=gnu99
LDFLAGS := -lev -lsqlite3

bin := bin/minircd
bin_srcs := $(wildcard src/*.c)
bin_objs := $(patsubst src/%.c,obj/%.o,${bin_srcs})
mod_srcs := $(wildcard modsrc/*.c)
mod_objs := $(patsubst modsrc/%.c,obj/mod_%.o,${mod_srcs})
CFLAGS += -DVERSION="\"$(MINIRCD_VERSION)\""
MOD_CFLAGS := ${CFLAGS}

prebuild:
	@echo "Building minircd ${MINIRCD_VERSION}"

postbuild:
	@echo "Success!"
	@echo ""
	@echo "You can now invoke $(MAKE) run or $(MAKE) install to finish"
	@echo ""

world: prebuild ${bin} modules postbuild

clean:
	${RM} -f ${bin_objs} ${mod_objs} ${bin}

${bin}: ${bin_objs}
	$(CC) ${LDFLAGS} -o ${bin} ${bin_objs}
	
modules: ${mod_objs}

obj/%.o:src/%.c GNUmakefile
	${CC} ${CFLAGS} -o $@ -c $<

obj/mod_%.o:modsrc/%.c GNUmakefile
	${CC} ${MOD_CFLAGS} -o $@ -c $<

run: ${bin}
	@./${bin}

.PHONY: all clean build

commit push pull:
	git $@
