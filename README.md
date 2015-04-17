# suriyaaos
(Very) basic UNIX-like operating system built for iSC OS.

![Screen](https://raw.githubusercontent.com/SamyPesse/How-to-Make-a-Computer-Operating-System/master/preview.png)


## What kind of OS are we building?

The	goal is	to build a very	simple UNIX-based	operating	system in	C++, not just	a	"proof-of-concept".	The	OS should	be able	to boot,	start	a	userland shell,	and	be extensible.

The	OS will	be built for the x86 architecture, running on	32 bits, and compatible	with IBM PCs.


### Specifications

* Code in	C++
* x86, 32	bit	architecture
* Boot with Grub
* Kind of modular	system for drivers
* Kind of UNIX style
* Multitasking
* ELF	executable in userland

Modules (accessible in userland using /suriyaa/...):
* IDE disks
* DOS
* partitions
* Clock
* EXT2 (read only)
* Boch
* VBE

Userland:
* API
* Posix
* LibC "Can" run a shell or some executables like Lua, ...
