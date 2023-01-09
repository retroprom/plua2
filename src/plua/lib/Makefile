LUA       = ../../..
include $(LUA)/config.palmos

LDFLAGS  = -L. -e start -nostartfiles
OBJS     = plualib.o plualib-dispatch.o
LIBS     = -lnfm

all: $(OBJS) 3dlib2.prc CasLib.prc ScreenLib.prc TestLib2.prc

.s.o:
	$(CC) $(CFLAGS) -c $<

3dlib2.prc: 3dlib.def 3dlib
	$(BUILDPRC) -o 3dlib2.prc 3dlib.def 3dlib

3dlib: $(OBJS) 3dlib.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) 3dlib.o $(LIBS) -o 3dlib

CasLib.prc: CasLib.def CasLib
	$(BUILDPRC) -o CasLib.prc CasLib.def CasLib

CasLib: $(OBJS) CasLib.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) CasLib.o $(LIBS) -o CasLib

ScreenLib.prc: ScreenLib.def ScreenLib
	$(BUILDPRC) -o ScreenLib.prc ScreenLib.def ScreenLib

ScreenLib: $(OBJS) ScreenLib.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) ScreenLib.o $(LIBS) -o ScreenLib

TestLib2.prc: TestLib.def TestLib
	$(BUILDPRC) -o TestLib2.prc TestLib.def TestLib

TestLib: $(OBJS) TestLib.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) TestLib.o $(LIBS) -o TestLib

clean:
	rm -f 3dlib.o 3dlib 3dlib2.prc
	rm -f CasLib.o CasLib CasLib.prc
	rm -f ScreenLib.o ScreenLib ScreenLib.prc
	rm -f TestLib.o TestLib TestLib2.prc
