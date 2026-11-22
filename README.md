# Embedded Linux Exercises

A collection of Embedded Linux exercises focused on Linux kernel modules, device drivers, and user-space testing.

## Exercises

### 1. Out-of-Tree Kernel Module

Directory: `out-of-tree/`

A basic Linux kernel module built outside the kernel source tree.

### 2. Kernel Patch

Directory: `kernel-patch/`

A patch-based exercise for integrating kernel module changes.

### 3. Device Driver Tests

Directory: `tests/`

- `test_mymodule.c` — Tests opening and closing a character device.
- `test_circular_buffer.c` — Tests writing and reading data through a character device using a circular buffer.

## Main Project

The continuously developed Buildroot kernel module is maintained in a separate repository:

[trivmod-buildroot-package](https://github.com/LavyCo/trivmod-buildroot-package)

## Environment

- Linux / Buildroot
- Raspberry Pi 5
- C programming
- Linux kernel modules
