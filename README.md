# Lockout

A console-based number guessing game where you crack multi-level codes to break into an emergency shelter during a nuclear apocalypse.

## Features

- **Number code cracking gameplay** — Deduce three secret numbers from their sum and product
- **Adjustable difficulty** — Choose from 5 difficulty levels; higher levels produce larger numbers
- **Progressive levels** — Work through each level from 1 up to your chosen difficulty
- **Retry on failure** — Incorrect guesses let you retry the current level rather than restarting
- **Colorful console output** — Uses Windows console text attributes for colored text feedback
- **Debug mode** — In Debug builds, the secret codes are printed for testing purposes

## Requirements

- **OS:** Windows (uses Windows API for console manipulation and colored text)
- **Compiler/IDE:** Microsoft Visual Studio 2017 or later (solution targets platform toolset v143)
- **Windows SDK:** 10.0

## Installation / Build Instructions

### Using Visual Studio

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/lockout.git
   ```
2. Open `lockout.sln` in Visual Studio.
3. Select your desired configuration (**Debug** or **Release**) and platform (**x86** or **x64**).
4. Build the solution (`Ctrl+Shift+B` or **Build → Build Solution**).
5. The compiled executable will be located in the `Debug/` or `Release/` output directory.

### Pre-built Binary

A pre-built Debug executable is available at `Debug/lockout.exe`.

## Usage

Run the executable from a Windows console:

```
lockout.exe
```

### Example Session

```
Enter a number 1 - 5 for level difficulty or 0 to quit.
Difficulty: 3


You can't get into the emergency shelter because you are LEVEL 3 locked out.
So, you'll need to enter the correct codes to get in AND the codes become more difficult as the level increases.
Enter each digit of the code with a space in between (e.g., 1 2 5) and then hit the enter key to see if you are correct!
Nobody likes being stuck in a nuclear apocalypse so get to it!

++ There are three numbers in the code.
++ The codes add-up to: 5
++ The codes multiply to give: 6
1 2 2

Yea!!! Almost there...you are now at level: 2
```

Enter `0` at the difficulty prompt to quit the game.

## How It Works

For each level, three random numbers are generated based on the current difficulty. You are given:
- The **sum** of the three numbers
- The **product** of the three numbers

Your goal is to figure out the three numbers. Enter them separated by spaces. If the sum and product of your guess match, you advance to the next level. Guess incorrectly and you retry the same level.

## Notes & Limitations

- **Windows only** — The game relies on the Windows API (`windows.h`) for console clearing and colored text output, so it will not compile or run on macOS/Linux without modification.
- Input validation is minimal; entering non-numeric values at the code guess prompt may cause unexpected behavior.
- Multiple valid combinations of three numbers can share the same sum and product — any valid combination is accepted.