#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int WIDTH = 40;
int HEIGHT = 20;

// Global high scores for each difficulty level
int highScoreEasy = 0;
int highScoreMedium = 0;
int highScoreHard = 0;

// Enumerations for snake movement and game difficulty
enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
enum Difficulty { EASY, MEDIUM, HARD };

class SnakeGame {
private:
    bool gameOver;
    int score;
    int x, y;           // Snake head position
    int foodX, foodY;   // Food position
    int tailX[100], tailY[100];  // Fixed-size arrays for the tail segments
    int tailLength;
    Direction dir;
    HANDLE console;     // Console handle for cursor manipulation
    Difficulty diffType; // Difficulty of this game instance

    // Function to place food randomly but not on the snake
    void spawnFood() {
        do {
            foodX = rand() % WIDTH;
            foodY = rand() % HEIGHT;
        } while (isFoodOnSnake());
    }
    
    // Checks if the new food location coincides with the snake's body
    bool isFoodOnSnake() {
        // Check head (optional) and tail segments
        if (x == foodX && y == foodY)
            return true;
        for (int i = 0; i < tailLength; i++) {
            if (tailX[i] == foodX && tailY[i] == foodY)
                return true;
        }
        return false;
    }
    
    // Sets the cursor to a given position in the console window
    void setCursorPosition(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(console, coord);
    }
    
    // Hides the blinking cursor in the console for a cleaner display
    void hideCursor() {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = 10;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(console, &cursorInfo);
    }
    
public:
    // Constructor now takes a difficulty parameter
    SnakeGame(Difficulty diff) : diffType(diff) {
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        resetGame();
    }
    
    // Resets game variables for a new game session
    void resetGame() {
        gameOver = false;
        dir = STOP;
        x = WIDTH / 2;
        y = HEIGHT / 2;
        score = 0;
        tailLength = 0;
        spawnFood();
        hideCursor();
    }
    
    // Draws the game board, snake, food, and borders.
    // When gameOver is true, the snake is drawn using 'x' instead of 'O' (head) and 'o' (tail)
    void draw() {
        setCursorPosition(0, 0); // Reposition the cursor to avoid flickering
        
        // Draw top border
        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;
        
        // Draw each row of the game area
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == 0)
                    cout << "#"; // Left border
                
                if (i == y && j == x) {
                    // Draw snake head: use 'x' when gameOver, else 'O'
                    cout << (gameOver ? "x" : "O");
                }
                else if (i == foodY && j == foodX) {
                    // Draw the food
                    cout << "F";
                }
                else {
                    bool printed = false;
                    // Check if this position is part of the tail
                    for (int k = 0; k < tailLength; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            // Draw tail segment: 'x' if game is over, else 'o'
                            cout << (gameOver ? "x" : "o");
                            printed = true;
                            break;
                        }
                    }
                    if (!printed)
                        cout << " "; // Empty space
                }
                
                if (j == WIDTH - 1)
                    cout << "#"; // Right border
            }
            cout << endl;
        }
        
        // Draw bottom border
        for (int i = 0; i < WIDTH + 2; i++) cout << "#";
        cout << endl;
        
        // Display the current score and the high score for the selected difficulty
        cout << "Score: " << score << " | High Score: ";
        if (diffType == EASY)
            cout << highScoreEasy;
        else if (diffType == MEDIUM)
            cout << highScoreMedium;
        else if (diffType == HARD)
            cout << highScoreHard;
        cout << endl;
    }
    
    // Reads user input to change the snake's direction or exit
    void input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'w': if (dir != DOWN) dir = UP; break;
                case 's': if (dir != UP) dir = DOWN; break;
                case 'a': if (dir != RIGHT) dir = LEFT; break;
                case 'd': if (dir != LEFT) dir = RIGHT; break;
                case 'x': gameOver = true; break;
            }
        }
    }
    
    // Updates the snake's position, handles tail movement, checks collisions, and handles food consumption
    void logic() {
        // Update tail: shift tail positions (each segment takes the place of the previous segment)
        int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < tailLength; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        
        // Move the snake's head based on the current direction
        switch (dir) {
            case UP:    y--; break;
            case DOWN:  y++; break;
            case LEFT:  x--; break;
            case RIGHT: x++; break;
            default: break;
        }
        
        // Check collision with walls (boundaries)
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
            gameOver = true;
        
        // Check collision with the tail (self-collision)
        for (int i = 0; i < tailLength; i++) {
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;
        }
        
        // Check if the snake has eaten the food
        if (x == foodX && y == foodY) {
            score += 10;
            tailLength++;
            spawnFood();
        }
        
        // Update the high score based on difficulty
        updateHighScore();
    }
    
    // Updates the global high score for the current difficulty if the current score is higher
    void updateHighScore() {
        if (diffType == EASY) {
            if (score > highScoreEasy)
                highScoreEasy = score;
        } else if (diffType == MEDIUM) {
            if (score > highScoreMedium)
                highScoreMedium = score;
        } else if (diffType == HARD) {
            if (score > highScoreHard)
                highScoreHard = score;
        }
    }
    
    // Returns whether the game is over
    bool isGameOver() {
        return gameOver;
    }
    
    // Returns the current score
    int getScore() {
        return score;
    }
    
    // Returns the high score for the current difficulty
    int getHighScore() {
        if (diffType == EASY)
            return highScoreEasy;
        else if (diffType == MEDIUM)
            return highScoreMedium;
        else // HARD
            return highScoreHard;
    }
};

// A busy-wait delay function (not optimized for CPU usage)
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
}

int main() {
    char choice;
    bool exitGame = false;
    
    // Outer loop: Main menu for difficulty selection
    while (!exitGame) {
        system("cls");
        cout << "Select difficulty level:" << endl;
        cout << "a) Easy  (200ms delay)" << endl;
        cout << "b) Medium (120ms delay)" << endl;
        cout << "c) Hard  (80ms delay)" << endl;
        cout << "x) Exit" << endl;
        char diffInput;
        cin >> diffInput;
        
        Difficulty currentDifficulty;
        int delayTime = 200;
        if (diffInput == 'a') {
            currentDifficulty = EASY;
            delayTime = 200;
        } else if (diffInput == 'b') {
            currentDifficulty = MEDIUM;
            delayTime = 120;
        } else if (diffInput == 'c') {
            currentDifficulty = HARD;
            delayTime = 80;
        } else if (diffInput == 'x') {
            break;
        } else {
            cout << "Enter proper difficulty level!" << endl;
            continue;
        }
        
        // Inner loop: Play game sessions in the chosen difficulty until the user goes back to the menu or exits
        bool backToMenu = false;
        while (!backToMenu) {
            SnakeGame game(currentDifficulty);
            // Game loop: runs until gameOver becomes true
            while (!game.isGameOver()) {
                game.draw();
                game.input();
                game.logic();
                delay(delayTime);
            }
            // Final draw to show the game-over state (snake now displayed with 'x')
            game.draw();
            cout << "Game Over!" << endl;
            cout << "Final Score: " << game.getScore() 
                 << " | High Score: " << game.getHighScore() << endl;
            cout << "Press 'p' to play again in the same difficulty, 'm' to return to menu, or 'x' to exit: ";
            cin >> choice;
            if (choice == 'p') {
                continue; // Start a new game in the same difficulty
            } else if (choice == 'm') {
                backToMenu = true; // Break out to the main menu for a new difficulty selection
            } else if (choice == 'x') {
                exitGame = true; // Exit the entire game
                break;
            }
        }
    }
    
    return 0;
}