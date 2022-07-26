APPNAME=lispy-test
SOURCEDIR=src
LDFLAGS=
LDLIBS=
SOURCES=$(shell find $(SOURCEDIR) -name "*.c" | sed "s|^\./||")
CFLAGS+=-MMD -std=c89
OUT=$(addprefix $(OUTDIR)/,$(APPNAME))
OBJECTS=$(addprefix $(OBJDIR)/,$(SOURCES:%=%.o))

ifndef config
	config=debug
endif

ifeq ($(config),debug)
	CFLAGS+=-g
	OBJDIR=debug
	OUTDIR=debug/bin
else
	CFLAGS+=-O3 -DNDEBUG
	OBJDIR=release
	OUTDIR=release/bin
endif

all: $(OUT) run

$(OUT): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $(OUT) $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(APPNAME) $(OBJECTS:%.o=%.d)

run: $(OUT)
	@./$(OUT)

test:
	$(MAKE) -C test

.PHONY: all clean run test

-include $(OBJECTS:%.o=%.d)
