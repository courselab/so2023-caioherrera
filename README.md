[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10954576&assignment_repo_type=AssignmentRepo)
# SO 2023 Projects
> 9008828 Caio Herrera (caioherrera@usp.br)

## Bare Metal Hello World
> Exercises solved on folder `./bare-metal-hw/`

**a) Implement your own version of the hello world program in machine code.**

    Edit the file hw.hex using `syseg/eg/hw/eg-00.hex` as reference.
    Avoid copying and pasting the code, though. Try to recreate it from
    your knowledge of x86 real-mode and legacy boot mechanism.

    Edit the Makefile to build hw-hex.bin.

    Test your code using the emulator.

    If it works, try booting it on your physical hardware.

       Note:

       You may need to add some extra code to satisfy idiosyncratic BIOSes.
       Consult the examples in `syseg/eg/hw`

> Check files `./bare-metal-hw/hw.hex` and `./bare-metal-hw/hw-hex.bin`

**b) Implement your own version of the hello world program in AT&T assembly.**

    Edit the hw.S using `syseg/eg/hw/eg-03.S` as reference.

    Repeat the tests mentioned in part (a).

> Check files `./bare-metal-hw/hw.S` and `./bare-metal-hw/hw-s.bin`

**c) Implement your own version of the hello world program in C.**

    Edit the file hw.c using `syseg/eg/hw/eg-08.c` as reference.

    Repeat the tests mentioned in part (a)	

> Check files `./bare-metal-hw/stdio.h`, `./bare-metal-hw/hw.c`, `./bare-metal-hw/hw_rt0.c`, `./bare-metal-hw/hw_utils.c` and `./bare-metal-hw/hw-c.bin`

## TinyOS - Part I
> Exercises solved on folder `./tyos/`

**a) Implement a function help() that prints a "help" message on the screen.**

    As a suggestion, writing directly into the video display memory
    can be accomplished with just plain C source code. On the other
    hand, you'd have to implement the usual tty behavior by hand.

**b) Implement a shell-like command processor.**

    The program should show a prompt on the screen, next to which the
    user can enter some single-world command.

    The command processor should then read the user input and proceed
    as follows.

    If the command corresponds to any built-in command, the referred
    command should be executed. Implement at least the command 'help',
    which executes the function help().

    When the command execution is complete, the program should show
    the prompt again and wait for the next command.

    If the command is not recognized, show an error message and get
    back to the prompt.

    Tips: - BIOS interrupt 16h gives access to the keyboard services. See https://en.wikipedia.org/wiki/INT_16H.

**c) Implement another command that uses some BIOS service.**

    Tips: - See https://en.wikipedia.org/wiki/BIOS_interrupt_call

    With BIOS services you can get current date, available memory etc.
