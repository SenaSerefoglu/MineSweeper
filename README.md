# MineSweeper
# Overview
This is a console-based implementation of the classic Minesweeper game written in C. The game features a 16x16 board with 40 randomly placed mines. The player must uncover all non-mine cells without triggering a mine.

# Features
- A 16x16 game board initialized at the start.
- Random placement of 40 mines.
- Numbering system indicating adjacent mines.
- Recursive reveal of empty spaces.
- Game restarts automatically upon hitting a mine.

# How to Play
1. Run the program in a terminal.
2. Enter the row and column indices (0-15) when prompted.
3. The game will reveal the selected cell:
   - If the cell contains a number, it indicates the number of adjacent mines.
   - If the cell is empty (0), adjacent cells will be revealed recursively.
   - If the cell contains a mine, the game ends and restarts automatically.
4. Continue revealing cells until all non-mine cells are uncovered.

# Code Structure
- **initializeBoard()**: Initializes the game board and places mines.
- **resetGame()**: Resets all game variables for a new game.
- **placeMines()**: Randomly places mines on the board.
- **calculateNumbers()**: Computes numbers indicating adjacent mines.
- **displayBoard()**: Displays the current game board.
- **revealCell(int x, int y)**: Reveals a cell and recursively reveals empty cells.
- **getUserInput()**: Prompts the user for input.
- **playGame()**: Main game loop handling user interaction.
- **gameOver()**: Handles game over scenarios and restarts the game.
- **main()**: Entry point of the program.

# Requirements
- GCC compiler (or any compatible C compiler)
- Standard C libraries (stdio.h, stdlib.h, time.h)

#Future Improvements
- Implement flagging for potential mines.
- Add a win condition check.
- Improve board display for better user experience.
- Allow custom board sizes and mine counts.

