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

// Food symbol (emoji or fallback)
string foodSymbol = "🍎"; // Apple emoji

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

// Function to display the grid
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
                cout << foodSymbol << " "; // Display food (emoji or fallback)
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

// Rest of the code remains the same...