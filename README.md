# tail

## Implementing *tail* command on xv6
The traditional UNIX tail utility can print out lines from the end of a file. If the number of lines is not configured (i.e., tail FILE), tail would print out the last 10 lines of its input. Or we could trigger by calling tail -NUM FILE, for example tail -2 README to print the last 2 lines of the file README. 

This program implements the *tail* command in C for the xv6 operating system.

## Examples of the usage of tail:

> $ tail README
To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run "make". On non-x86 or
 → non-ELF machines (like OS X, even on x86), you will need to install a cross-compiler
 → gcc suite capable of producing x86 ELF binaries. See
 → http://pdos.csail.mit.edu/6.828/2014/tools.html. Then run "make
 → TOOLPREFIX=i386-jos-elf-". To run xv6, install the QEMU PC simulators. To run in
 → QEMU, run "make qemu".
To create a typeset version of the code, run "make xv6.pdf". This requires the "mpage"
 → utility. See http://www.mesa.nl/pub/mpage/.
 
---

> $ grep the README | tail
Version 6 (v6). xv6 loosely follows the structure and style of v6, xv6 borrows code from
 → the following sources: JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and
 → others) Plan 9 (entryother.S, mp.h, mp.c, lapic.c) In addition, we are grateful for
 → the bug reports and patches contributed by
The code in the files that constitute xv6 is To run xv6, install the QEMU PC simulators.
 → To run in QEMU, run "make qemu".
To create a typeset version of the code, run "make xv6.pdf". This requires the "mpage"  → utility. See http://www.mesa.nl/pub/mpage/.

---

>$ tail -2 README
To create a typeset version of the code, run "make xv6.pdf". This requires the "mpage"
 → utility. See http://www.mesa.nl/pub/mpage/.’’’ 