SDKDIR=./sdk

help:
	@echo "Makefile for Building Suriyaa Operating System (sOS)."
	@echo "Usage: make [ all | clean | help | build | run] " 
	@echo ""
	@echo

all: 
	@echo "Building (Linux) Kernel"
	make -C ./kernel
	@echo "Building SDK"
	make -C ./sdk
	@echo "Building Userland"
	make -C ./userland
	

build:
	zip -r devos-$(VERSION).zip ./


run:
	@echo "Running Suriyaa Operating System (sOS)."
	cd ./sdk && sudo bash ./diskimage.sh
	cd ./sdk && qemu.exe

clean:
	make -C ./kernel clean
	make -C ./userland clean
