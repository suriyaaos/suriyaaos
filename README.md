# suriyaaOS [![Travis Build Status](https://img.shields.io/travis/suriyaaos/suriyaaos.svg?style=flat-square)](https://travis-ci.org/suriyaaos/suriyaaos)

 <img src="https://upload.wikimedia.org/wikipedia/commons/2/26/SuriyaaOS-logo.png"
 hspace="20" align="left" height="333"/>

<!-- Non-breaking space -->
&nbsp;

> A simple, basic, open-sourced UNIX-like operating system built by [Suriyaa][creator].

**Notice:** This ReadMe only documents a subset of suriyaaOS's features. For additional documentation please see the [suriyaaOS site][suriyaaos].

<!-- Non-breaking space -->
&nbsp;


## What kind of OS is suriyaaOS built?

The goal is to build a very simple [UNIX][unix]-based operating	system in C++, not just	a "proof-of-concept". The OS should be able to boot, start a userland shell, and be extensible.

The OS will be built for the x86 architecture, running on 32 bits, and compatible with IBM PCs. It also works as a virtual machine nearly on all similar computers like [Windows][win], [Mac][mac] & [Linux][lin].


## Specifications & Features

 * Code in C++
 * x86-architecture -> 32-bits
 * Boot with (GNU) Grub
 * Kind of modular system for drivers (it's not really great)
 * Kind of UNIX style (again: It's not great)
 * Multitasking
 * ELF executable in userland (-> kernel.elf)
 * Modules (accessible in userland using /suriyaa/...):
	* IDE disks
	* DOS partitions
	* Clock
	* EXT2 (read only)
	* Boch VBE
 * Userland:
	* API Posix
	* LibC
	* "Can" run a shell or some excutables like [Lua][lua], ...
 * Supports [ASCII][ascii] and [OSCII][oscii] [8][oscii8] standard scheme


## Prerequisites

### For a Physical Machine

Buy or build a computer using x86 architecture. It should be compatible with IBM PCs.

### For a Virtual Machine

You will need [Vagrant][vagrant] and [VirtualBox][oraclevm] or [QEMU][qemu] installed. Read the [`INSTALL.md`][install] file.

![suriyaaOS in a Virtual Machine on a Mac PC](https://raw.githubusercontent.com/SamyPesse/How-to-Make-a-Computer-Operating-System/master/preview.png)


## Progress

  - :white_check_mark: Compiles
  - :white_check_mark: Builds Image
  - :white_check_mark: Boots


## Documentation

Find more information in these files:

 * suriyaaOS Contributors: [`AUTHORS.md`][authors]
 * How to contribute to suriyaaOS: [`CONTRIBUTING.md`][contrib]
 * Frequently Asked Questions: [`FAQ.md`][faq]
 * Help me: [`HELP.md`][help]
 * How to install suriyaaOS: [`INSTALL.md`][install]
 * Copyright information: [`LICENSE.md`][license]
 * Questions & Issues: [`QUESTIONS.md`][quest]
 * About suriyaaOS: [`README.md`][readme]
 * References: [`SUMMARY.md`][summary]


## License

Copyright © 2015-present [Suriyaa Sundararuban][creator]. All rights reserved.

Distributed under the Apache License 2.0. See [`LICENSE.md`][license] file for more copyright informations.


<!-- Links -->
[suriyaaos]: https://suriyaaos.github.io/
[creator]: https://about.suriyaa.tk
[github]: https://github.com/suriyaaos/suriyaaos

[unix]: https://en.wikipedia.org/wiki/UNIX
[win]: http://windows.microsoft.com/en-US/windows/home
[mac]: https://www.apple.com/mac/
[lin]: http://www.linux-foundation.org/

[lua]: https://www.lua.org/
[ascii]: https://en.wikipedia.org/wiki/ASCII
[oscii]: https://github.com/osciicode
[oscii8]: https://osciicode.github.io/oscii8/

[vagrant]: https://www.vagrantup.com/
[oraclevm]: https://www.virtualbox.org/
[qemu]: http://wiki.qemu.org/Main_Page

[authors]: ./AUTHORS.md
[contrib]: ./CONTRIBUTING.md
[faq]: ./FAQ.md
[help]: ./HELP.md
[install]: ./INSTALL.md
[license]: ./LICENSE.md
[quest]: ./QUESTIONS.md
[readme]: ./README.md
[summary]: ./SUMMARY.md
