# Installation guide

> More/Other informations under [how-to-create-an-operating-system.pdf](https://github.com/SuriyaaKudoIsc/suriyaaos/blob/4f6bb618a663e68a131c6f325ba2202ca4f90503/how-to-create-an-operating-system.pdf).


## Install Vagrant

Download Vagrant under [www.vagrantup.com](https://www.vagrantup.com/) and install it. Than run it under your command line:

    vagrant	box add	lucid32	http://files.vagrantup.com/lucid32.box

I use *Vagrant 1.8.1 for Windows* ([Download this version](https://releases.hashicorp.com/vagrant/1.8.1/vagrant_1.8.1.msi)).

## Install Oracle VM VirtualBox

Download VirtualBox under [www.virtualbox.org](https://www.virtualbox.org/) ([Download website](https://download.virtualbox.org/virtualbox/)) and install it.
I used *[VirtualBox-4.3.30-101610-Win.exe](https://download.virtualbox.org/virtualbox/4.3.30/VirtualBox-4.3.30-101610-Win.exe)* file to install VirtualBox v4.3.30 for Windows on my Windows 10.


## Install GNU GRUB

We don't need to install GRUB. It's pre-installed in suriyaaOS! :-)


## Build & Run using Vagrant (for Windows, OS X and Linux users)

Download the .zip-File and extract it.

Make sure you have both Vagrant installed and this repo cloned (and an open terminal/cmd in it's folder)

```bash
    # Enter the folder
    cd suriyaaos
```

Then run the following commands (ignore comment lines starting with #):

```bash
    # Starts Vagrant VM
    # This will start an ubuntu machine and install build-essential, make, Qemu ...
    vagrant up

    # SSH into machine
    vagrant ssh

    # Once SSHed
    cd /vagrant

    # Build kernel, userland ...
    make all

    # Run emulation
    make emulate
```
