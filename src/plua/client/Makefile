LUA       = ../../..
include $(LUA)/config.palmos

PROG     = client
OBJS     = client.o

EXTRA_INCS= -I$(LUA)/src/plua

all: $(PROG).prc

$(PROG).prc: $(PROG) $(PROG).def res
	$(BUILDPRC) $(PROG).def $(PROG)

$(PROG): $(PROG).o
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

res: resource.rcp
	$(PILRC) resource.rcp .
	touch res

clean:
	rm -f *.[oasS] $(PROG) *.bin res $(PROG).prc *.grc
