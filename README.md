# Plua 2 Continued

Copyright (C) 2003-2006 Tecgraf, PUC-Rio.  
Copyright (C) 2001-2022 Marcio Migueletto de Andrade.  
Copyright (C) 2022 Cameron Kaiser.  
All rights reserved.  
Licensed under the GNU Public License v3 (see `LICENSE`).

Plua is a port of Lua 5.0.3 to classic Palm OS (3.5 or later) with special on-board support for the Palm Pilot hardware, including graphics, sound, UI and networking. For more about Plua, including full documentation, see [Plua Revisited](http://www.floodgap.com/retrotech/plua/).

This is the source code for the onboard Lua IDE (`Plua2.prc`), the help facility (`Plua2Help.prc`) and the runtime (`Plua2RT.prc`). Your compiled app need only be distributed with the runtime, though you must also include a copy of `MathLib.prc` and any C-libraries you built. A pre-built `MathLib.prc` is available from Plua Revisited.

Although the source code for the `plua2c` "cross-compiler" is necessarily part of this source archive, for a 64-bit fixed version compatible with most modern operating systems, see the separate [`plua2c` source code](https://github.com/classilla/plua2c). (Among other things, it's a lot easier to build!)

## Building Plua2

Plua 2's build system requires the following:

* `prc-tools` 2.3
* `pilrc` 3.2
* `multilink` 0.3

These are admittedly difficult build requirements, as `prc-tools` is not 64-bit friendly and does not compile on many modern operating systems. `x86` users may be able to use [`prc-tools-remix`](https://github.com/jichu4n/prc-tools-remix). The source code for `multilink` is available from [its home page](http://www.djw.org/product/palm/multilink/) but you may need to build the dependent specialized [`libbfd`](http://www.djw.org/product/palm/multilink/libbfd.html) it requires separately. Source code for a 64-bit fixed version of `pilrc` is available from Plua Revisited.

By default, the build system expects the PalmOne SDK to be present at `/opt/palmdev/PalmOne` (such that `/opt/palmdev/PalmOne/Incs` exists) and the 68K COFF library fragments used by `multilink` in `/usr/local/lib/m68k-palmos-multilink`. In addition, the `prc-tools` binaries should be in your path. If this is not the case on your system, change `./config.palmos`. You can get a copy of the PalmOne SDK (and others) from [this Github archive](https://github.com/jichu4n/palm-os-sdk).

With the system thus configured, type `make` to build the Palm OS binaries, which will be deposited in `bin/palmos`. These are PRCs which can be installed directly into POSE or your real Palm hardware. `make clean` will clear any intermediate artifacts and the final objects.

Currently Plua is built on a Power Mac G5 Quad (and sometimes an iMac G4) running a Mac OS X Tiger (10.4) build of `prc-tools` and `multilink`, and an updated copy of `pilrc`. These systems run the compiler and linker in 32-bit mode, avoiding issues with 64-bit systems.

## Things to do next

Support the AlphaSmart dana's wide screen.

Support for built-in WiFi with Sony Cli&eacute; devices (currently this doesn't seem to report when a network transmission has completed).

Allow chaining of apps (either native applications or Plua scripts) using something like `SysUIAppSwitch()`.

## Please don't ...

Please don't open issues for feature requests unless you intend to work on them. There is plenty of work to do.
