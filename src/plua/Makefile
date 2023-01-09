LUA       = ../..
include $(LUA)/config.palmos

PROG      = plua2

LIBS      = $(LIB)/liblua.a $(LIB)/liblualib.a libnfm.a libnfm2.a $(PALM_LIBDIR)/libPalmOSGlue.a
LDFLAGS   = -L.

OBJS      = main.o app.o p.o text.o error.o db.o doc.o rsrc.o \
	    memolist.o doclist.o streamlist.o vfslist.o file.o list.o \
            luac.o prefs.o link.o compile.o serial.o scroll.o \
            help.o vsprintf.o hr.o bmp.o fill.o sound.o midi.o editor.o \
            sprite.o gcontrol.o handler.o MathLib.o check.o

LOBJS     = lgraphlib.o lplualib.o

all: $(BIN)/$(PROG).prc

res: resource.tmp
	$(PILRC) resource.tmp .
	touch res

resource.tmp: Makefile resource.rcp
	sed -e "s/@@VERSION@@/$(VERSION)/g" < resource.rcp > resource.tmp

$(BIN)/$(PROG).prc: $(OBJS) $(LOBJS) $(LIBS) res
	m68k-palmos-multilink -basename PLUA -segmentsize 29k -nostdlib -fid LuaP $(OBJS) $(LOBJS) $(LIBS)
	rm -f pref0000.PLUA.grc
	cp pref0000.dat pref0000.PLUA.grc
	$(BUILDPRC) $(BIN)/$(PROG).prc Plua2 LuaP *.PLUA.grc *.bin

clean:
	rm -f *.[o] *.bin *.PLUA.grc res $(BIN)/$(PROG).prc PLUA*.out resource.tmp
