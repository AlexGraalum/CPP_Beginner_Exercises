//Includes
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Defines
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_SPC 32

#define play_comp

//Prototypes
void getKeyInput(int c, int idx[2]);
void printBoard(int board[3][3], int idx[2]);
int checkForSpot(int board[3][3], int idx[2], int turn);
bool checkForWin(int board[3][3]);
void stateWinner(int player);
void getCompPlay(int board[3][3]);
bool canBlockPlayer(int board[3][3]);
int blockPlayer(int board[3][3], int idx[2]);

//Functions
int main(int argc, char** argv) {
     //int board[9] = { 0,0,0, 
     //                 0,0,0, 
     //                 0,0,0 };
     int board[3][3] = { {0,0,0},
                         {0,0,0},
                         {0,0,0} };
     int idx[2] = { 0, 0 };
     int turn = 0;

     srand(time(NULL));

     while(1){
          system("CLS");

          printBoard(board, idx);
          if (checkForWin(board)) break;

#ifdef play_comp
          if (turn == 0) {
#endif
               int c = _getch();
               if (c == KEY_ESC) break;
               if (c == KEY_SPC) {
                    turn = checkForSpot(board, idx, turn);
               }
               else {
                    getKeyInput(c, idx);
               }
#ifdef play_comp
          }
          else {
               if (!canBlockPlayer(board)) {
                    getCompPlay(board);
               }
               turn = 0;
          }
#endif
     }
     return 0;
}

////Get User Input
//Use _getch for key values
//Check for arrow key code to avoid double input
void getKeyInput(int c, int idx[2]) {
     if (c == 224) {
          c = _getch();
          switch (c) {
          case KEY_UP:
               if (idx[1] > 0) idx[1]--;
               break;
          case KEY_DOWN:
               if (idx[1] < 2) idx[1]++;
               break;
          case KEY_LEFT:
               if (idx[0] > 0) idx[0]--;
               break;
          case KEY_RIGHT:
               if (idx[0] < 2) idx[0]++;
               break;
          default:
               break;
          }
     }
}

////Print the Tic Tac Toe Board
//Print square brackets for each space
//Use curly brackets for the current selection
//Print blank, X, or O in each space
void printBoard(int board[3][3], int idx[2]) {
     //int i = (idx[1] * 3) + idx[0];
     for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
               // [ ] OR [X] OR [O]
               int j = (y * 3) + x;
               std::cout << (((idx[0] == x) && (idx[1] == y)) ? "{" : "[");
               std::cout << ((board[x][y] == 0) ? " " : (board[x][y] == 1) ? "X" : "O");
               std::cout << (((idx[0] == x) && (idx[1] == y)) ? "}" : "]");

               //std::cout << ((i == j) ? "{" : "[")
               //     << ((board[j] == 0) ? " " : (board[j] == 1) ? "X" : "O")
               //     << ((i == j) ? "}" : "]");
          }
          std::cout << std::endl;
     }
}

////Check If Spot Is Open
//Check if the current selection is available
//Swap the turn to next player
int checkForSpot(int board[3][3], int idx[2], int turn) {
     //int i = (idx[1] * 3) + idx[0];
     //if (board[i] != 0) return turn;
     if (board[idx[0]][idx[1]] != 0) return turn;

     if (turn == 0) {
          board[idx[0]][idx[1]] = 1;
          return 1;
     }
     else {
          board[idx[0]][idx[1]] = 2;
          return 0;
     }
}

//                                        0 1 2
////Check If A Player Has Won           0 * * *
//Check the 5 key spaces for a win      1 * _ _
//Announce the winner on win            2 * _ _
bool checkForWin(int board[3][3]) {
     if (board[0][0] != 0) {
          if ((board[0][0] == board[1][0] && board[0][0] == board[2][0])        //  0 1 2
           || (board[0][0] == board[0][1] && board[0][0] == board[0][2])        //0 * * *
           || (board[0][0] == board[1][1] && board[0][0] == board[2][2])) {     //1 * * _
               stateWinner(board[0][0]);                                        //2 * _ *
               return true;
          }
     }
     if (board[1][0] != 0) {
          if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) {       //  0 1 2
               stateWinner(board[1][0]);                                        //0 _ * _
               return true;                                                     //1 _ * _
          }                                                                     //2 _ * _
     }
     if (board[2][0] != 0) {
          if ((board[2][0] == board[1][1] && board[2][0] == board[0][2])        //  0 1 2
           || (board[2][0] == board[2][1] && board[2][1] == board[2][2])) {     //0 _ _ *
               stateWinner(board[2][0]);                                        //1 _ * *
               return true;                                                     //2 * _ *
          }
     }
     if (board[0][1] != 0) {
          if (board[0][1] == board[1][1] && board[0][1] == board[2][1]) {       //  0 1 2
               stateWinner(board[0][1]);                                        //0 _ _ _
               return true;                                                     //1 * * *
          }                                                                     //2 _ _ _
     }
     if (board[0][2] != 0) {
          if (board[0][2] == board[1][2] && board[0][2] == board[2][2]) {       //  0 1 2
               stateWinner(board[0][2]);                                        //0 _ _ _
               return true;                                                     //1 _ _ _
          }                                                                     //2 * * *
     }
     return false;
}

////Announce Winner
//Announce which Player won, or if Comp won
void stateWinner(int player) {
#ifndef play_comp
     std::cout << "Congrats! Player " << player << " won!\n";
#else
     std::cout << "Congrats! " << (player == 1 ? "Player" : "Computer") << " won!\n";
#endif
}

////Let The Computer Play
//Choose a random position
//Check if it's already taken
void getCompPlay(int board[3][3]) {
     int x, y;

     do {
          x = rand() % 3;
          y = rand() % 3;
     } while (board[x][y] != 0);

     board[x][y] = 2;
}

////Can Computer Block Player
//Check if the player can be blocked
bool canBlockPlayer(int board[3][3]) {
     for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
               int idx[2] = {x, y};

          }
     }
     return false;
}

////Block The Player
//
int blockPlayer(int board[3][3], int idx[2]) {
     return 0;
}