# Installation guide

> More informations under [how-to-create-an-operating-system.pdf](https://github.com/SuriyaaKudoIsc/suriyaaos/blob/4f6bb618a663e68a131c6f325ba2202ca4f90503/how-to-create-an-operating-system.pdf).

## Install Vagrant

Download it under [www.vagrantup.com](https://www.vagrantup.com/] and install it. Than run it:

    vagrant	box add	lucid32	http://files.vagrantup.com/lucid32.box

## Install Oracle VM VirtualBox

Download it under [www.virtualbox.org](https://www.virtualbox.org/) ([Download website](https://download.virtualbox.org/virtualbox/)) and install it.
I used *[VirtualBox-4.3.30-101610-Win.exe](https://download.virtualbox.org/virtualbox/4.3.30/VirtualBox-4.3.30-101610-Win.exe)* file to install VirtualBox v4.3.30 for Windows on my Windows 10.

## Run Vagrant

Download the .zip-File and extract it. If you want to run it on Windows 10 put the folder under `C:\User\YourUsername`.
I put that under `C:\Users\Suriyaa`.

After that type this into your command line:

    cd suriyaaos
    vagrant	up
    vagrant ssh
    cd /vagrant

## Run with `make`

    make all
    make run

# Usage

## Login

Login with user name **"`vagrant`"** and password **"`vagrant`"**!
