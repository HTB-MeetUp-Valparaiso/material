# Pwn 101

Meant for learning the basics of Pwn regarding userland memory corruption vulnerabilities, specifically what's a Buffer Overflow (BOF), how a BOF arises in C code as it would appear in the old times (before awareness of BOFs) and new times (when code source base complexity increases), what can you do with it and more importantly: a little of Linux + x86 ASM basics in order to better understand the underlying issues.

At the end you will find a listing of more topics and techniques in modern pwning in order to hype up motivation for this area and attempt to showcase the general context of binary exploitation as a job, hobby and whatnot.

## Examples
### Requirements

In order to start playing with these toy examples to follow the slides, you will need the following plugins for GDB (besides having python3 and gdb).

```bash
$ # pwntools
$ pip install pwntools
$ # pwndbg
$ git clone https://github.com/pwndbg/pwndbg
$ cd pwndbg
$ ./setup.sh
```
### Usage

These example programs made in C can be found at dir `examples/` and should be compiled with GCC using the following flags to make debugging and stack smashing more simple.

```bash
$ # no ASLR and canary for this binary (fixed address)
$ gcc simple_bof_fgets.c -no-pie -fno-stack-protector -o simple_bof
```

Then, you can use the python script to follow along in the debugger!

```bash
$ python3 template.py GDB
```

I encourage you to tinker with the script and learn gdb commands in order to move in the execution steps on GDB.