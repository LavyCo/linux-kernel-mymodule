# Linux Kernel Module Exercise

A simple Linux kernel module for Raspberry Pi 5.

In this exercise, I created an out-of-tree kernel module, compiled it using Buildroot, and tested it on the Raspberry Pi using `insmod`, `lsmod`, and `rmmod`.

The module prints "Hello World" when loaded and "Bye Bye World" when removed.

I also created a patch to add the module to the Linux kernel source under `drivers/`.

## Buildroot Package

I also created a Buildroot package for the kernel module.

The package includes `Config.in`, `Makefile`, `mymodule.mk`, and `mymodule.c`.

I enabled the package in Buildroot, built a new image, and tested the module on Raspberry Pi 5.

The module was loaded using `modprobe` and removed using `rmmod`. I verified the Hello World and Bye Bye World messages using `dmesg`.

## Character Device Registration

I extended the module to register a character device.

- Used `alloc_chrdev_region()` to dynamically allocate a device number.
- Added a static `cdev` structure.
- Used `cdev_init()` and `cdev_add()` to register the character device.
- Used `cdev_del()` and `unregister_chrdev_region()` to clean up when removing the module.

I rebuilt the module using Buildroot and transferred the `.ko` file to the Raspberry Pi using SCP, without rebuilding or flashing the entire image.

I tested the module using `insmod` and verified that it appeared in `/proc/devices` with major number 240.

After removing the module using `rmmod`, I verified that it disappeared from `/proc/devices`.

## Device File Creation

I extended the module to automatically create a device file.

- Used `class_create()` to create a device class.
- Used `device_create()` to register the device and create `/dev/mymodule`.
- Added `device_destroy()` and `class_destroy()` to clean up when removing the module.
- Added error handling for device registration and creation failures.

I rebuilt the module using Buildroot and transferred the updated `.ko` file to the Raspberry Pi using SCP.

After loading the module, I verified that:

- `/sys/class/mymodule` was created.
- `/dev/mymodule` was created as a character device.
- The device was assigned major number 240 and minor number 0.

After removing the module using `rmmod`, I verified that both `/sys/class/mymodule` and `/dev/mymodule` were removed successfully.
