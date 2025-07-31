#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 25
#define CAR_WIDTH 3
#define CAR_HEIGHT 2
#define OBSTACLE_WIDTH 3
#define OBSTACLE_HEIGHT 1

// Game structures
typedef struct {
    int x, y;
    int width, height;
} GameObject;

typedef struct {
    GameObject car;
    GameObject obstacles[10];
    int obstacleCount;
    int score;
    int lives;
    bool gameOver;
    int level;
    int speed;
} GameState;

// Global variables
GameState game;
char screen[HEIGHT][WIDTH];

// Function prototypes
void initGame();
void drawScreen();
void updateGame();
void handleInput();
void moveCar(int dx);
void spawnObstacle();
void updateObstacles();
bool checkCollision(GameObject obj1, GameObject obj2);
void clearScreen();
void gotoxy(int x, int y);
void setColor(int color);
void drawCar(int x, int y);
void drawObstacle(int x, int y);
void drawRoad();
void showGameOver();
void showMenu();

// Colors
#define COLOR_RED 12
#define COLOR_GREEN 10
#define COLOR_BLUE 9
#define COLOR_YELLOW 14
#define COLOR_WHITE 15
#define COLOR_GRAY 8

int main() {
    srand(time(NULL));
    system("cls");
    showMenu();
    
    while (1) {
        initGame();
        
        while (!game.gameOver) {
            handleInput();
            updateGame();
            drawScreen();
            Sleep(100 - game.speed);
        }
        
        showGameOver();
        
        printf("\nPress 'R' to restart or 'Q' to quit: ");
        char choice = getch();
        if (choice == 'q' || choice == 'Q') {
            break;
        }
    }
    
    return 0;
}

void initGame() {
    // Initialize car
    game.car.x = WIDTH / 2;
    game.car.y = HEIGHT - 5;
    game.car.width = CAR_WIDTH;
    game.car.height = CAR_HEIGHT;
    
    // Initialize obstacles
    game.obstacleCount = 0;
    game.score = 0;
    game.lives = 3;
    game.gameOver = false;
    game.level = 1;
    game.speed = 10;
    
    // Clear screen buffer
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

void drawScreen() {
    clearScreen();
    gotoxy(0, 0);
    
    // Draw road
    drawRoad();
    
    // Draw car
    drawCar(game.car.x, game.car.y);
    
    // Draw obstacles
    for (int i = 0; i < game.obstacleCount; i++) {
        drawObstacle(game.obstacles[i].x, game.obstacles[i].y);
    }
    
    // Draw UI
    gotoxy(0, HEIGHT + 1);
    setColor(COLOR_WHITE);
    printf("Score: %d | Lives: %d | Level: %d | Speed: %d", 
           game.score, game.lives, game.level, game.speed);
    
    gotoxy(0, HEIGHT + 2);
    printf("Controls: A/D - Move | Q - Quit");
}

void updateGame() {
    // Spawn obstacles
    if (rand() % 20 == 0) {
        spawnObstacle();
    }
    
    // Update obstacles
    updateObstacles();
    
    // Check collisions
    for (int i = 0; i < game.obstacleCount; i++) {
        if (checkCollision(game.car, game.obstacles[i])) {
            game.lives--;
            if (game.lives <= 0) {
                game.gameOver = true;
            } else {
                // Remove the obstacle that caused collision
                for (int j = i; j < game.obstacleCount - 1; j++) {
                    game.obstacles[j] = game.obstacles[j + 1];
                }
                game.obstacleCount--;
            }
            break;
        }
    }
    
    // Update score and level
    game.score += 1;
    if (game.score % 100 == 0) {
        game.level++;
        game.speed = min(80, game.speed + 5);
    }
}

void handleInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'a':
            case 'A':
                moveCar(-1);
                break;
            case 'd':
            case 'D':
                moveCar(1);
                break;
            case 'q':
            case 'Q':
                game.gameOver = true;
                break;
        }
    }
}

void moveCar(int dx) {
    int newX = game.car.x + dx;
    if (newX >= 0 && newX + game.car.width <= WIDTH) {
        game.car.x = newX;
    }
}

void spawnObstacle() {
    if (game.obstacleCount < 10) {
        GameObject obstacle;
        obstacle.x = rand() % (WIDTH - OBSTACLE_WIDTH);
        obstacle.y = 0;
        obstacle.width = OBSTACLE_WIDTH;
        obstacle.height = OBSTACLE_HEIGHT;
        
        game.obstacles[game.obstacleCount] = obstacle;
        game.obstacleCount++;
    }
}

void updateObstacles() {
    for (int i = 0; i < game.obstacleCount; i++) {
        game.obstacles[i].y++;
        
        // Remove obstacles that are off screen
        if (game.obstacles[i].y >= HEIGHT) {
            for (int j = i; j < game.obstacleCount - 1; j++) {
                game.obstacles[j] = game.obstacles[j + 1];
            }
            game.obstacleCount--;
            i--;
        }
    }
}

bool checkCollision(GameObject obj1, GameObject obj2) {
    return (obj1.x < obj2.x + obj2.width &&
            obj1.x + obj1.width > obj2.x &&
            obj1.y < obj2.y + obj2.height &&
            obj1.y + obj1.height > obj2.y);
}

void clearScreen() {
    system("cls");
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawCar(int x, int y) {
    setColor(COLOR_RED);
    gotoxy(x, y);
    printf("███");
    gotoxy(x, y + 1);
    printf("███");
}

void drawObstacle(int x, int y) {
    setColor(COLOR_YELLOW);
    gotoxy(x, y);
    printf("███");
}

void drawRoad() {
    setColor(COLOR_GRAY);
    for (int i = 0; i < HEIGHT; i++) {
        gotoxy(0, i);
        printf("│");
        gotoxy(WIDTH - 1, i);
        printf("│");
    }
    
    // Draw road markings
    setColor(COLOR_WHITE);
    for (int i = 0; i < HEIGHT; i += 2) {
        gotoxy(WIDTH / 2, i);
        printf("│");
    }
}

void showGameOver() {
    clearScreen();
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2 - 2);
    setColor(COLOR_RED);
    printf("╔══════════════════════════════════════╗");
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2 - 1);
    printf("║           GAME OVER!                ║");
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2);
    printf("║           Final Score: %-8d        ║", game.score);
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2 + 1);
    printf("║           Level Reached: %-8d      ║", game.level);
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2 + 2);
    printf("╚══════════════════════════════════════╝");
    
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 4);
    setColor(COLOR_WHITE);
    printf("Press 'R' to restart or 'Q' to quit");
}

void showMenu() {
    clearScreen();
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 - 4);
    setColor(COLOR_BLUE);
    printf("╔══════════════════════════════════════════════════════╗");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 - 3);
    printf("║                    CAR RACING GAME                  ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 - 2);
    printf("╠══════════════════════════════════════════════════════╣");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 - 1);
    printf("║  Controls:                                          ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2);
    printf("║  A/D - Move car left/right                         ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 1);
    printf("║  Q - Quit game                                     ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 2);
    printf("╠══════════════════════════════════════════════════════╣");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 3);
    printf("║  Objective:                                         ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 4);
    printf("║  Avoid yellow obstacles and survive as long as      ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 5);
    printf("║  possible to get the highest score!                ║");
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 6);
    printf("╚══════════════════════════════════════════════════════╝");
    
    gotoxy(WIDTH / 2 - 15, HEIGHT / 2 + 8);
    setColor(COLOR_GREEN);
    printf("Press any key to start the game...");
    getch();
}
