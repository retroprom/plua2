LUA       = ../../..
include $(LUA)/config.palmos

PROG      = plua2rt

LIBS      = $(LIB)/liblua.a $(LIB)/liblualib.a ../libnfm.a ../libnfm2.a $(PALM_LIBDIR)/libPalmOSGlue.a
LDFLAGS   = -L.

OBJS      = ../main.o ../app.o ../p.o ../text.o ../error.o ../db.o ../rsrc.o \
            ../doc.o ../file.o ../serial.o ../scroll.o ../vsprintf.o ../hr.o ../bmp.o ../fill.o \
            ../sound.o ../midi.o ../sprite.o ../gcontrol.o ../handler.o ../MathLib.o ../check.o stubs.o

LOBJS     = ../lgraphlib.o ../lplualib.o

EXTRA_INCS= -I$(LUA)/src/plua

all: $(BIN)/$(PROG).prc

res: resource.tmp
	$(PILRC) resource.tmp .
	touch res

resource.tmp: Makefile resource.rcp
	sed -e "s/@@VERSION@@/$(VERSION)/g" < resource.rcp > resource.tmp

$(BIN)/$(PROG).prc: $(OBJS) $(LOBJS) $(LIBS) res
	m68k-palmos-multilink -basename RLUA -segmentsize 29k -nostdlib -fid LuaR $(OBJS) $(LOBJS) $(LIBS)
	rm -f pref0000.RLUA.grc
	cp ../pref0000.dat pref0000.RLUA.grc
	$(BUILDPRC) $(BIN)/$(PROG).prc Plua2RT LuaR *.RLUA.grc *.bin

clean:
	rm -f *.[o] *.bin *.RLUA.grc res $(BIN)/$(PROG).prc RLUA*.out resource.tmp

