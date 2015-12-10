# suriyaaOS (sOS)

> (Very) basic UNIX-like operating system built for iSC Enterprise Group operating systems.


![(Vagrant) Screen](https://raw.githubusercontent.com/SamyPesse/How-to-Make-a-Computer-Operating-System/master/preview.png)


## What kind of OS is suriyaaOS built?

The	goal is	to build a very	simple UNIX-based	operating	system in	C++, not just	a	"proof-of-concept".	The	OS should	be able	to boot,	start	a	userland shell,	and	be extensible.

The	OS will	be built for the x86 architecture, running on	32 bits, and compatible	with IBM PCs. (It also works as a virtual machine nearly on all computers like Windows, Mac & Linux!)


## Specifications & Features

	* Code in C++
	* x86-architecture -> 32-bits
	* Boot with (GNU) Grub
	* Kind of modular system for drivers (it's not really great)
	* Kind of UNIX style (again: It's not great)
	* Multitasking
	* ELF executable in userland (-> kernel.elf)
	* Modules (accessible in userland using /suriyaa/...) :
		* IDE disks
		* DOS partitions
		* Clock
		* EXT2 (read only)
		* Boch VBE
	* Userland :
		* API Posix
		* LibC
		* "Can" run a shell or some excutables like Lua, ...


## Progress

  - :white_check_mark: Compiles
  - :white_check_mark: Builds Image
  - :white_check_mark: Boots
