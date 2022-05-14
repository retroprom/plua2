/**********
 * Copyright (c) 2004-2005 Greg Parker.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GREG PARKER ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********/

#ifndef PEAL_H
#define PEAL_H

#include <stdint.h>

/*
  PealModule *PealLoad(void *mem)
    Loads ARM code and data from mem.
    If mem points into a relocatable block, that block must be locked before 
      calling PealLoad() and must remain locked until after PealUnload().
    Note that PealLoad() may modify *mem. If mem points into a resource 
      or feature memory block, then mem must point to the beginning of 
      the block and the memory must be writeable with DmWrite().
    Returns NULL if the load fails for any reason.
    Warning: if you do not call PealUnload() before your program exits, 
      your program may crash with a handle lock overflow error when run 
      more than 16 times.

  PealModule *PealLoadFromResources(DmTypeID type, DmResID baseID)
    Loads ARM code and data from resources of the given type, starting 
      with the given resource ID.
    The resources should be numbered sequentially starting with baseID, 
      one for the ELF header and section list plus one for each ELF section. 
      This is the output format generated by `peal-postlink -s ...`.
    DmGetResource() is used to load the resources. Some sections with 
      no contents may have no resource, but still occupy a slot in the 
      resource ID sequence. Some of the resources are kept open and 
      locked until PealUnload() is called.
    Note that some of the resources may be modified using DmWrite().
    Returns NULL if the load fails for any reason.
    Warning: if you do not call PealUnload() before your program exits, 
      your program may crash with a handle lock overflow error when run 
      more than 16 times.

  void PealUnload(PealModule *m)
    Unloads ARM code and data previously loaded by PealLoad().
    The module must not be used after this call.
    Warning: if you do not call PealUnload() before your program exits, 
      your program may crash with a handle lock overflow error when run 
      more than 16 times.
    
  void *PealLookupSymbol(PealModule *m, char *query)
    Returns the address of a named ARM function or variable in module m.
    Returns NULL if the module contains no such function or variable.
    A function can be called by passing this address to PealCall().
    A variable can be read or written by dereferencing this address.

  uint32_t PealCall(PealModule *m, void *addr, void *arg)
    Calls the function at addr in ARM module m, passing it the given arg.
    Returns the value returned by that function.
    The ARM function PealArmStub() is used to prepare ARM global state.
    The called function should take zero or one arguments.

  void PealCxxConstruct(PealModule *m)
    Calls C++ constructors if they have not been called already.
    By default, Peal calls C++ constructors (if any) during the 
    first PealCall(). You can force C++ constructors to run earlier 
    by calling PealCxxConstruct() directly. 
    The constructors are run only once, even if you call 
    PealCxxConstruct() multiple times.

  void PealCxxDestruct(PealModule *m)
    Calls C++ destructors if they have not been called already.
    By default, Peal calls C++ destructors (if any) during the 
    PealUnload(). You can force C++ destructors to run earlier 
    by calling PealCxxDestruct() directly. 
    The destructors are run only once, even if you call 
    PealCxxDestruct() multiple times.
 */


typedef struct PealModule PealModule;

PealModule *PealLoad(void *elf);
PealModule *PealLoadFromResources(DmResType type, DmResID baseID);
void PealUnload(PealModule *m);

void *PealLookupSymbol(PealModule *m, char *query);

uint32_t PealCall(PealModule *m, void *addr, void *arg);

void PealCxxConstruct(PealModule *m);
void PealCxxDestruct(PealModule *m);

#endif
