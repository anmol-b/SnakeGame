# Snake Game

This is a simple implmentation of the famous Snake game. This C++ application opens a simple console based UI and let's user play in a loop until they decide to quit.

Game Features:
- Move the snake with keys w-a-s-d for up-left-down-right directions respectively.
- Snake can move trough the walls and reappear from the opposite side.
- Fruit appears randomly on screen, represented by the character 'F'
- The game is over if snake runs into itself, including prodviding opposite direction command. Example, if the snake is going up and user provides instruction as 'down' this implies snake ran into itself, ergo, the game is over.
- When the game is over, user gets the option to restart the game or quite the application.


To compile this use either g++ or gcc.

Example with g++:

```
> g++ initialize.cpp Snake.cpp Utilities.cpp -o snake.exe
```

### What it looks like
![Screen grab GIF of the game](https://user-images.githubusercontent.com/3617819/148100682-e30774af-8eab-42a4-abe3-75733e17cd36.gif)

