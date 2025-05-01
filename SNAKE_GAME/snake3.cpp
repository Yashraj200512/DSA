#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int GRID_SIZE = 10;
const int SNAKE_INITIAL_LENGTH = 3;

enum Direction { UP, DOWN, LEFT, RIGHT };

vector<pair<int, int>> snake;
pair<int, int> food;
Direction direction = RIGHT;
int score = 0;

void clearScreen() {
    system("cls");
}

void initializeGame() {
    snake.clear();
    for (int i = 0; i < SNAKE_INITIAL_LENGTH; i++) {
        snake.push_back({GRID_SIZE / 2, GRID_SIZE / 2 - i});
    }

    srand(time(0));
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
}

void displayGrid() {
    clearScreen();

    for (int x = 0; x < GRID_SIZE + 2; x++) {
        cout << "_ ";
    }
    cout << endl;

    for (int y = 0; y < GRID_SIZE; y++) {
        cout << "| ";
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
                cout << "F ";
            } else {
                cout << "  ";
            }
        }
        cout << "|" << endl;
    }

    for (int x = 0; x < GRID_SIZE + 2; x++) {
        cout << "_ ";
    }
    cout << endl;

    cout << "Score: " << score << endl;
}

void updateGame() {
    pair<int, int> newHead = snake[0];
    switch (direction) {
        case UP: newHead.second--; break;
        case DOWN: newHead.second++; break;
        case LEFT: newHead.first--; break;
        case RIGHT: newHead.first++; break;
    }

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

    if (newHead == food) {
        score++;
        snake.insert(snake.begin(), newHead);

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
        snake.insert(snake.begin(), newHead);
        snake.pop_back();
    }
}

void handleInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'w': if (direction != DOWN) direction = UP; break;
            case 's': if (direction != UP) direction = DOWN; break;
            case 'a': if (direction != RIGHT) direction = LEFT; break;
            case 'd': if (direction != LEFT) direction = RIGHT; break;
            case 'x': exit(0);
        }
    }
}

void displayInstructions() {
    cout << "Welcome to Snake Game!" << endl;
    cout << "Instructions:" << endl;
    cout << "1. Press 'Enter' to start the game." << endl;
    cout << "2. Use 'W', 'A', 'S', 'D' to control the snake." << endl;
    cout << "3. Press 'X' to exit the game." << endl;
    cout << "4. Eat the food (F) to grow the snake and increase your score." << endl;
    cout << "5. Avoid hitting the walls or yourself!" << endl;
    cout << "Press 'Enter' to begin..." << endl;

    while (true) {
        if (_kbhit() && _getch() == '\r') {
            break;
        }
    }
}

int main() {
    displayInstructions();
    initializeGame();
    while (true) {
        displayGrid();
        handleInput();
        updateGame();
        Sleep(200);
    }
    return 0;
}
