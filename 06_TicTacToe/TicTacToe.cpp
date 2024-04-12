//Includes
#include <iostream>
#include <conio.h>

//Defines
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_SPC 32

//Prototypes
void getKeyInput(int, int[]);
void printBoard(int[], int[]);
int checkForSpot(int[], int[], int);
bool checkForWin(int[]);

//Functions
int main(int argc, char** argv) {
     int board[9] = { 0,0,0, 
                      0,0,0, 
                      0,0,0 };
     int idx[] = { 0, 0 };
     int turn = 0;

     while(1){
          system("CLS");

          printBoard(board, idx);
          if (checkForWin(board)) break;

          int c = _getch();
          if (c == KEY_ESC) break;
          getKeyInput(c, idx);
          if (c == KEY_SPC) {
               turn  = checkForSpot(board, idx, turn);
          }

     }
     return 0;
}

////Get User Input
//Use _getch for key values
//Check for arrow key code to avoid double input
void getKeyInput(int c, int idx[]) {
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
void printBoard(int board[], int idx[]) {
     int i = (idx[1] * 3) + idx[0];
     for (int y = 0; y < 3; y++) {
          for (int x = 0; x < 3; x++) {
               // [ ] OR [X] OR [O]
               int j = (y * 3) + x;
               std::cout << ((i == j) ? "{" : "[")
                    << ((board[j] == 0) ? " " : (board[j] == 1) ? "X" : "O")
                    << ((i == j) ? "}" : "]");
          }
          std::cout << std::endl;
     }
}

////Check If Spot Is Open
//Check if the current selection is available
//Swap the turn to next player
int checkForSpot(int board[], int idx[], int turn) {
     int i = (idx[1] * 3) + idx[0];
     if (board[i] != 0) return turn;

     if (turn == 0) {
          board[i] = 1;
          return 1;
     }
     else {
          board[i] = 2;
          return 0;
     }
}

////Check If A Player Has Won
//Check the 5 key spaces for a win
//Announce the winner on win
bool checkForWin(int board[]) {
     //0 1 2
     //3 _ _
     //6 _ _
     if (board[0] != 0) {
          //0 1 2
          //3 4 _
          //6 _ 8
          if ((board[0] == board[1] && board[0] == board[2])
               || (board[0] == board[3] && board[0] == board[6])
               || (board[0] == board[4] && board[0] == board[8])) {
               std::cout << "Congrats! Player " << board[0] << " won!\n";
               return true;
          }
     }
     if (board[1] != 0) {
          //_ 1 _
          //_ 4 _
          //_ 7 _
          if (board[1] == board[4] && board[1] == board[7]) {
               std::cout << "Congrats! Player " << board[1] << " won!\n";
               return true;
          }
     }
     if (board[2] != 0) {
          //_ _ 2
          //_ 4 5
          //6 _ 8
          if ((board[2] == board[4] && board[2] == board[6])
               || (board[2] == board[5] && board[2] == board[8])) {
               std::cout << "Congrats! Player " << board[2] << " won!\n";
               return true;
          }
     }
     if (board[3] != 0) {
          //_ _ _
          //3 4 5
          //_ _ _
          if (board[3] == board[4] && board[3] == board[5]) {
               std::cout << "Congrats! Player " << board[3] << " won!\n";
               return true;
          }
     }
     if (board[6] != 0) {
          //_ _ _
          //_ _ _
          //6 7 8
          if (board[6] == board[7] && board[6] == board[8]) {
               std::cout << "Congrats! Player " << board[6] << " won!\n";
               return true;
          }
     }
     return false;
}