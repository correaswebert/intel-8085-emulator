## Intel 8085 Emulator

8085 is a 8-bit microprocessor. The emulator emulates all the non I/O instructions.

The assembly instructions could be fed through:

- a file
- typed by user at runtime (via the terminal)

The emulator understands hex codes. But it can also parse assembly instructions  
into their corresponding hex codes. Basic error checking is implemented, i.e.,  
the emulator stops at the first occurence of any error. You can view the contents  
of registers during the process, and the values of the memory after you have  
halted the runtime.

Follow the instructions to _start_ the emulator.

```shell
# compile the emulator code
make

# <addr>:      the starting address of your machine code in memory
# <filename>:  the name of the file you want to use.
#              it need not reside in codes/ but is preferable.

# to compile your assemble code into machine code
# <addr> is optional, it defaults to 0000
bin/cc codes/<filename>.asm <addr>

# <addr> refers to the start address of your machine code in memory

# (optional) to read your machine code as assembly code
bin/rc codes/<filename>.mc <addr>

# run your machine code on emulator
bin/main codes/<filename>.mc <addr>

# now your program has started emulating!
```

Follow the instructions to _run_ the emulator.

- Press ENTER to continue after the splash screen showing your code

- Enter any runtime data you want to provide

  - Enter the memory address (Press ENTER)
  - Enter the data (Press ENTER)
  - Use the shortcuts displayed: **p**revious, **n**ext, **q**uit

- You will be prompted if you wish for stepwise execution (0: no | 1: yes)  
  (If stepwise execution selected, press ENTER to go to next instruction.)

- After execution of your code, you can view the memory contents  
  by enteringthe memory address.

- Enter **q** to quit.
