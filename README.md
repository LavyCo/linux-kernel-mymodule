# Linux Kernel Module Exercise

A simple Hello World kernel module for Raspberry Pi 5.

In this exercise, I created an out-of-tree kernel module, compiled it using Buildroot, and tested it on the Raspberry Pi using `insmod`, `lsmod`, and `rmmod`.

The module prints "Hello World" when loaded and "Bye Bye World" when removed.

I also created a patch to add the module to the Linux kernel source under `drivers/`.
## Buildroot Package

I also created a Buildroot package for the kernel module.

The package includes Config.in, Makefile, mymodule.mk,
and mymodule.c.

I enabled the package in Buildroot, built a new image,
and tested the module on Raspberry Pi 5.

The module was loaded using modprobe and removed using
rmmod. I verified the Hello World and Bye Bye World
messages using dmesg.
