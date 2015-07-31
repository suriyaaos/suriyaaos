# Installation guide

> More informations under [how-to-create-an-operating-system.pdf](https://github.com/SuriyaaKudoIsc/suriyaaos/blob/4f6bb618a663e68a131c6f325ba2202ca4f90503/how-to-create-an-operating-system.pdf).

## Install Vagrant

Download it under vagrantup.com and install it. Than run it:

    vagrant	box add	lucid32	http://files.vagrantup.com/lucid32.box

## Run Vagrant

Download the .zip-File and extract it. If you want to run it on Windows 8.1 put the folder under `C:\YourUsername`.
I put that under `C:\Suriyaa`.

After that type this into your command line:

    cd suriyaaos
    vagrant	up
    vagrant ssh
    cd /vagrant

## Run with `make`

    make all
    make run
