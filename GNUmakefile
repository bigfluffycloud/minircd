MINIRCD_VERSION=0.0.1

all: world
CFLAGS := -Wall -ansi -pedantic -std=gnu99
LDFLAGS := -lev

bin := bin/minircd
srcs = $(wildcard src/*.c)
objs = $(patsubst src/%.c,obj/%.o,${srcs})

CFLAGS += -DVERSION="\"$(MINIRCD_VERSION)\""

prebuild:
	@echo "Building minircd ${MINIRCD_VERSION}"

postbuild:
	@echo "Success!"
	@echo ""
	@echo "You can now invoke $(MAKE) run or $(MAKE) install to finish"
	@echo ""

world: prebuild ${bin} postbuild

clean:
	${RM} -f ${objs} ${bin}

${bin}: ${objs}
	$(CC) -o ${bin} ${objs}
	
obj/%.o:src/%.c GNUmakefile
	${CC} ${CFLAGS} -o $@ -c $<

run: ${bin}
	@./${bin}

.PHONY: all clean build

