#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 10;
int dinoPos;
bool isJumping;
int jumpHeight;
int score;
int obstacle;

string dino[4] = {
    "  __",
    " /oo\\",
    "/    \\",
    "\\____/"
};
//######################################################################## SETUP FUNCTION ##############################################################################################
void Setup() {
    gameOver = false;
    dinoPos = height - 4; 
    isJumping = false;
    jumpHeight = 0;
    score = 0;
    obstacle = width - 1;
}
//####################################################################### DRAW FUNCTION ####################################################################################
void Draw() {
    system("cls");


    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;


    for (int i = 0; i < height; i++) {
        cout << "#"; 
        for (int j = 0; j < width; j++) {
        
            if (i >= dinoPos && i < dinoPos + 4 && j == 1) {
                cout << dino[i - dinoPos];
                j += dino[i - dinoPos].length() - 1; 
            }
            
            else if (i == height - 1 && j == obstacle)
                cout << "|";
            else
                cout << " ";
        }
        cout << "#" << endl; 
    }

    
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}
//################################################################# INPUT FUNCTION ########################################################################################
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case ' ':
            if (!isJumping) {
                isJumping = true;
                jumpHeight = 4;
            }
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
//############################################################## LOGIC FUNCTION ############################################################################################
void Logic() {

    if (isJumping) {
        dinoPos--;
        jumpHeight--;
        if (jumpHeight <= 0) {
            isJumping = false;
        }
    } else if (dinoPos < height - 4) {
        dinoPos++; 
    }


    obstacle--;
    if (obstacle < 0) {
        obstacle = width - 1;
        score++;
    }

    
    if (obstacle >= 1 && obstacle <= 5 && dinoPos + 3 >= height - 1) {
        gameOver = true;
    }

    Sleep(100);
}
//############################################################# MAIN FUNCTION #############################################################################################
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }

    system("cls");
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;
    return 0;
}
