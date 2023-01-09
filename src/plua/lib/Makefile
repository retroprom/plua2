LUA       = ../../..
include $(LUA)/config.palmos

LDFLAGS  = -L. -e start -nostartfiles
OBJS     = plualib.o plualib-dispatch.o
LIBS     = -lnfm

all: $(OBJS)

.s.o:
	$(CC) $(CFLAGS) -c $<
