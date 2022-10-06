/*
Shreya Suresh
10/6/22
TicTacToe- Play a two player game of tic tac toe in the command line. Displays wins and tie count. 
 */
#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
void move(char (&board)[3][3], int &turn);
void restart(bool (&stillPlaying), int X_WINS, int O_WINS, int numTies, int &turn);
void clearBoard(char (&board)[3][3], int &turn);
bool checkWin(char (&board)[3][3], int &turn);
bool checkTie(char (&board)[3][3], int &turn);


bool stillPlaying = true;
char board[3][3];
int X_TURN = 0;
int O_TURN = 1;
int turn = X_TURN;
int X_WINS = 0;
int O_WINS = 0;
int numTies = 0;
char BLANK = ' ';
int round = 0;

int main(){
  clearBoard(board, turn);
  while(stillPlaying == true){
  move(board, turn);
  printBoard(board);
    if (checkWin(board, turn) == true){ // if players win, count and restart game
      if (turn == X_TURN){
      X_WINS++;
      round++;
    } else {
      O_WINS++;
      round++;
    }
      restart(stillPlaying, X_WINS, O_WINS, numTies, turn);
      if (stillPlaying == true){
      clearBoard(board, turn);
      } else {
	return 0;
      }
  }
    else if (checkTie(board, turn) == true){ // if players tie, count and restart game
      numTies++;
      round++;
      restart(stillPlaying, X_WINS, O_WINS, numTies, turn);
      if (stillPlaying == true){
      clearBoard(board, turn);
      } else {
	return 0;
      }
    }
  }
  return 0;
}

void move( char (&board)[3][3], int &turn){ // play a move on the board
  char input[3];
  int x;
  int y;
  cout << "Whats your move?" << endl;
  cin >> input;
   
  if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){ //check if row is valid
    cout << "Row must be an a, b, or c" << endl;
     if (turn == X_TURN){
          turn = O_TURN;
        } else if (turn == O_TURN){
          turn = X_TURN;
        }
  } else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){ //check if column is valid
    cout << "Column must be a 1, 2, or 3" << endl;
     if (turn == X_TURN){
          turn = O_TURN;
        } else if (turn == O_TURN){
          turn = X_TURN;
        }
  } else { // set the x and y coordinates to move to
      if (input[0] == 'a'){
        x = 0;
      } else if (input[0] == 'b'){
        x = 1;
      } else if (input[0] == 'c'){
        x = 2;
      }
      if (input[1] == '1'){
        y = 0;
      } else if (input[1] == '2'){
        y = 1;
      } else if (input[1] == '3'){
        y = 2;
      }
      if (board[x][y] == BLANK){
	if (turn == X_TURN){
	  board[x][y] = 'X';
	  return;
    }
	if (turn == O_TURN){
	  board[x][y] = 'O';
	  return;
    }
      } else if (board[x][y] != BLANK){ //check if spot is taken
	cout << "This spot is taken" << endl;
	if (turn == X_TURN){
	  turn = O_TURN;
	} else if (turn == O_TURN){
	  turn = X_TURN;
	}
	return; 
      }
  }
}

void restart(bool (&stillPlaying), int X_WINS, int O_WINS, int numTies, int &turn){ // display scores and start new game
  cout << "Round " << round  << " over." << endl;
  cout << "Current stats:" << endl;
  cout << "X Wins: " << X_WINS << endl;
  cout << "O wins: " << O_WINS << endl;
  cout << "Ties: " << numTies << endl;

  stillPlaying = true;
 }

void printBoard(char board[3][3]){ // print the board
    cout << " 123" << endl;
    cout << "a" << board[0][0] << board[0][1] << board[0][2] << endl; // print row 1
    cout << "b" << board[1][0] << board[1][1] << board[1][2] << endl; // print row 2
    cout << "c" << board[2][0] << board[2][1] << board[2][2] << endl; // print row 3
  }

void clearBoard(char (&board)[3][3], int &turn){ // reset the board
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = ' ';
      turn = X_TURN;
    }
  }
  printBoard(board);
}

bool checkTie(char (&board)[3][3], int &turn){ // check if players have tied
  if (turn == X_TURN){
    turn = O_TURN;
  } else {
    turn = X_TURN;
  }
  for (int row = 0; row < 3; row++){ //check if all spots are full
    for (int col = 0; col < 3; col++){
      if (board[row][col] == BLANK){
	return false;
      }
    }
  }
  return true;
}
 bool checkWin(char (&board)[3][3], int &turn){ // check all win possibilities
  char temp  = ' ';
  if (turn == X_TURN){ //switch turns
    temp = 'X';
      } else {
    temp = 'O';
  }
  if (board[0][0] == temp && board[0][1] == temp && board[0][2] == temp){
    return true;
  } if (board[0][0] == temp && board[1][1] == temp && board[2][2] == temp) {
    return true;
  } if (board[0][1] == temp && board[1][1] == temp && board[2][1] == temp) { 
    return true;
  } if (board[0][2] == temp && board[1][2] == temp && board[2][2] == temp) { 
    return true;
  } if (board[1][0] == temp && board[1][1] == temp && board[1][2] == temp) { 
    return true;
  } if (board[2][0] == temp && board[2][1] == temp && board[2][2] == temp) { 
    return true;
  } if (board[0][2] == temp && board[1][1] == temp && board[2][0] == temp) { 
    return true;
  } if (board[0][0] == temp && board[1][0] == temp && board[2][0] == temp){
    return true;
  }
  return false;
}

