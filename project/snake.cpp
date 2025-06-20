#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <thread>

using namespace std;

class SnakeGame {
private:
    int width, height;
    int score;
    bool gameOver;
    int x, y, fruitX, fruitY, tailLength;
    vector<pair<int, int> > tail;

public:
    SnakeGame(int w = 20, int h = 17) {
        width = w;
        height = h;
        score = 0;
        gameOver = false;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tailLength = 0;
    }

    void Draw() {
        system("clear");
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "#";
                if (i == y && j == x) cout << "O"; // Head of the snake
                else if (i == fruitY && j == fruitX) cout << "F"; // Fruit
                else {
                    bool printed = false;
                    for (int k = 0; k < tailLength; k++) {
                        if (tail[k].first == j && tail[k].second == i) {
                            cout << "o"; // Body of the snake
                            printed = true;
                            break;
                        }
                    }
                    if (!printed) cout << " ";
                }

                if (j == width - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    // Non-blocking keyboard input
    char GetInput() {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ICANON; // Disable canonical mode
        newt.c_lflag &= ~ECHO;   // Disable echoing
        newt.c_cc[VMIN] = 1;
        newt.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    void Input() {
        char current = GetInput();
        if (current == 'a') x--;
        if (current == 'd') x++;
        if (current == 'w') y--;
        if (current == 's') y++;
        if (current == 'x') gameOver = true;
    }

    void Logic() {
        int prevX = tail.empty() ? x : tail[0].first;
        int prevY = tail.empty() ? y : tail[0].second;
        int prev2X, prev2Y;
        
        // Store the head position and move the tail
        tail.push_back(make_pair(prevX, prevY)); // Use make_pair to insert

        if (tail.size() > tailLength) {
            tail.erase(tail.begin());
        }

        // Update the position of the snake's body
        for (int i = tailLength - 1; i > 0; i--) {
            tail[i] = tail[i - 1];
        }
        if (tailLength > 0) {
            tail[0] = make_pair(x, y); // Use make_pair for the head
        }

        // Handle boundary conditions
        if (x >= width) x = 0; else if (x < 0) x = width - 1;
        if (y >= height) y = 0; else if (y < 0) y = height - 1;

        // Check for collision with the body
        for (int i = 0; i < tailLength; i++) {
            if (tail[i].first == x && tail[i].second == y) {
                gameOver = true;
            }
        }

        // Check for fruit collision
        if (x == fruitX && y == fruitY) {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            tailLength++;
        }
    }

    bool IsGameOver() {
        return gameOver;
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust speed of game
        }
    }
};

int main() {
    SnakeGame game;
    game.Run();
    return 0;
}
