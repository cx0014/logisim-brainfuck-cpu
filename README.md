# logisim-brainfuck-cpu
A Logisim circuit that can run Brainfuck programs

## How to use
1. Use the attached bf_compiler.cpp to translate your Brainfuck source code (source.bf) into hexadecimal format
2. Copy the program output into the ROM of the circuit (top left corner) in Logisim
3. Enable clock ticks, set the tick frequency to the highest one available and start the Logisim simulation
4. Enter inputs when the LED next to the screen is on

## Translation table between BF commands and ROM instructions
| Hexadecimal | Brainfuck command                              |
| ----------- | ---------------------------------------------- |
| 0           | (program halts)                                |
| 1           | `>`: loops back to address 0000 if overflow    |
| 2           | `<`: loops back to address ffff if underflow   |
| 3           | `+`: loops back to value 0x00 if overflow      |
| 4           | `-`: loops back to value 0xff if underflow     |
| 5           | `.`: treats bits 0~6 as ASCII character        |
| 6           | `,`: accepts one byte from keyboard each time  |
| 7           | `[`                                            |
| 8           | `]`                                            |
| 9~f         | (no operation; program continues)              |

## Limitations
- Due to a design flaw of the circuit, a buffer half-byte must be added after each instruction, which costs clock cycles and ROM space
- There is no method (that I know of) to enter \0 into the keyboard buffer, so this may cause issues with programs that use \0 as an input termination character
- The circuit is unoptimized; it could use fewer components
