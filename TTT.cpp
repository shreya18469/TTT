#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
void move(char (&board)[3][3], int &turn);
void restart(bool &playAgainb, int X_WINS, int O_WINS, int numTies, int &turn);
void clearBoard(char (&board)[3][3], int &turn);
bool checkWin(char (&board)[3][3], int &turn);
bool checkTie(char (&board)[3][3], int &turn);


bool playAgainb = true;
char board[3][3];
int X_TURN = 0;
int O_TURN = 1;
int turn = X_TURN;
int X_WINS = 0;
int O_WINS = 0;
int numTies = 0;
char BLANK = ' ';

int main(){
  clearBoard(board, turn);
  while(playAgainb == true){
    move(board, turn);
    printBoard(board);
    if (checkWin(board, turn) == true){
      if (turn == X_TURN){
      X_WINS++;
    } else {
      O_WINS++;
    }
    restart(playAgainb, X_WINS, O_WINS, numTies, turn);
    if (playAgainb == true){
      clearBoard(board, turn);
    } else {
      return 0;
    }
  }
  else if (checkTie(board, turn) == true){
      numTies++;
      restart(playAgainb, X_WINS, O_WINS, numTies, turn);
      if (playAgainb == true){
	clearBoard(board, turn);
      } else {
	return 0;
      }
    }
  }
  return 0;
}

void move( char (&board)[3][3], int &turn){
  char input[3];
  int x;
  int y;
  bool invalidInput = true;
  cout << "Whats your move?" << endl;
  cin >> input;
   
  if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
    cout << "Row must be an a, b, or c" << endl;
     if (turn == X_TURN){
          turn = O_TURN;
        } else if (turn == O_TURN){
          turn = X_TURN;
        }
      } else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){
    cout << "Column must be a 1, 2, or 3" << endl;
     if (turn == X_TURN){
          turn = O_TURN;
        } else if (turn == O_TURN){
          turn = X_TURN;
        }
  } else {
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
      } else if (board[x][y] != BLANK){
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

void restart(bool &playAgainb, int X_WINS, int O_WINS, int numTies, int &turn){
  cout << "Current stats:" << endl;
  cout << "X Wins: " << X_WINS << endl;
  cout << "O wins: " << O_WINS << endl;
  cout << "Ties: " << numTies << endl;
  
    playAgainb = true;
 }

void printBoard(char board[3][3]){
    cout << " 123" << endl;
    cout << "a" << board[0][0] << board[0][1] << board[0][2] << endl;
    cout << "b" << board[1][0] << board[1][1] << board[1][2] << endl;
    cout << "c" << board[2][0] << board[2][1] << board[2][2] << endl;
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

bool checkTie(char (&board)[3][3], int &turn){
  if (turn == X_TURN){
    turn = O_TURN;
  } else {
    turn = X_TURN;
  }
  for (int row = 0; row < 3; row++){
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
  if (turn == X_TURN){
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

