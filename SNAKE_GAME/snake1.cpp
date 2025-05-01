#include <iostream>
#include <vector>
#include <conio.h> // For keyboard input
#include <windows.h> // For Sleep() and clearing the screen
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

// Constants
const int GRID_SIZE = 10;
const int SNAKE_INITIAL_LENGTH = 3;

// Directions
enum Direction { UP, DOWN, LEFT, RIGHT };

// Game variables
vector<pair<int, int>> snake; // Snake's body (x, y coordinates)
pair<int, int> food; // Food position
Direction direction = RIGHT; // Initial direction
int score = 0;

// Function to clear the screen
void clearScreen() {
    system("cls"); // For Windows
    // system("clear"); // For Linux/Mac
}

// Function to initialize the game
void initializeGame() {
    // Initialize snake
    snake.clear();
    for (int i = 0; i < SNAKE_INITIAL_LENGTH; i++) {
        snake.push_back({GRID_SIZE / 2, GRID_SIZE / 2 - i});
    }

    // Initialize food
    srand(time(0));
    food.first = rand() % GRID_SIZE;
    food.second = rand() % GRID_SIZE;

    // Ensure food does not spawn on the snake's body
    while (true) {
        bool onSnake = false;
        for (auto segment : snake) {
            if (food == segment) {
                onSnake = true;
                break;
            }
        }
        if (!onSnake) break;
        food.first = rand() % GRID_SIZE;
        food.second = rand() % GRID_SIZE;
    }
}

// Function to display the grid with visible boundaries
void displayGrid() {
    clearScreen();

    // Draw top boundary
    for (int x = 0; x < GRID_SIZE + 2; x++) {
        cout << "_ ";
    }
    cout << endl;

    // Draw grid with left and right boundaries
    for (int y = 0; y < GRID_SIZE; y++) {
        cout << "| "; // Left boundary
        for (int x = 0; x < GRID_SIZE; x++) {
            bool isSnakeSegment = false;
            for (auto segment : snake) {
                if (segment.first == x && segment.second == y) {
                    isSnakeSegment = true;
                    break;
                }
            }
            if (isSnakeSegment) {
                cout << "O ";
            } else if (x == food.first && y == food.second) {
               string foodSymbol = "🍎"; // Default to emoji
#ifdef _WIN32
// Check if running on Windows Command Prompt (which may not support emojis)
foodSymbol = "@"; // Fallback to a regular character
#endif
               
                cout << "🍎 ";
            } else {
                cout << "  ";
            }
        }
        cout << "|" << endl; // Right boundary
    }

    // Draw bottom boundary
    for (int x = 0; x < GRID_SIZE + 2; x++) {
        cout << "_ ";
    }
    cout << endl;

    // Display score
    cout << "Score: " << score << endl;
}

// Function to update the game state
void updateGame() {
    // Get the new head position
    pair<int, int> newHead = snake[0];
    switch (direction) {
        case UP: newHead.second--; break;
        case DOWN: newHead.second++; break;
        case LEFT: newHead.first--; break;
        case RIGHT: newHead.first++; break;
    }

    // Check for collisions
    if (newHead.first < 0 || newHead.first >= GRID_SIZE || newHead.second < 0 || newHead.second >= GRID_SIZE) {
        cout << "Game Over! You hit the wall." << endl;
        exit(0);
    }
    for (auto segment : snake) {
        if (newHead == segment) {
            cout << "Game Over! You collided with yourself." << endl;
            exit(0);
        }
    }

    // Check if food is eaten
    if (newHead == food) {
        score++;
        snake.insert(snake.begin(), newHead);

        // Generate new food
        food.first = rand() % GRID_SIZE;
        food.second = rand() % GRID_SIZE;
        while (true) {
            bool onSnake = false;
            for (auto segment : snake) {
                if (food == segment) {
                    onSnake = true;
                    break;
                }
            }
            if (!onSnake) break;
            food.first = rand() % GRID_SIZE;
            food.second = rand() % GRID_SIZE;
        }
    } else {
        // Move snake
        snake.insert(snake.begin(), newHead);
        snake.pop_back();
    }
}

// Function to handle keyboard input
void handleInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'w': if (direction != DOWN) direction = UP; break;
            case 's': if (direction != UP) direction = DOWN; break;
            case 'a': if (direction != RIGHT) direction = LEFT; break;
            case 'd': if (direction != LEFT) direction = RIGHT; break;
            case 'x': exit(0); // Exit the game
        }
    }
}

// Function to display game instructions
void displayInstructions() {
    cout << "Welcome to Snake Game!" << endl;
    cout << "Instructions:" << endl;
    cout << "1. Press 'Enter' to start the game." << endl;
    cout << "2. Use 'W', 'A', 'S', 'D' to control the snake." << endl;
    cout << "3. Press 'X' to exit the game." << endl;
    cout << "4. Eat the food (F) to grow the snake and increase your score." << endl;
    cout << "5. Avoid hitting the walls or yourself!" << endl;
    cout << "Press 'Enter' to begin..." << endl;

    // Wait for the user to press Enter
    while (true) {
        if (_kbhit() && _getch() == '\r') { // '\r' is the Enter key
            break;
        }
    }
}

// Main game loop
int main() {
    displayInstructions(); // Show instructions at the start
    initializeGame();
    while (true) {
        displayGrid();
        handleInput();
        updateGame();
        Sleep(200); // Control game speed (200ms delay)
    }
    return 0;
}