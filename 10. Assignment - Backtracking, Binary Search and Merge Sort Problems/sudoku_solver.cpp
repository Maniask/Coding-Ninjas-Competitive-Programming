
/*
Sudoku Solver

Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), 
you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.

Input Format :
9 Lines where ith line contains ith row elements separated by space

Output Format :
true or false

Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

#include<bits/stdc++.h>
using namespace std;

bool isBoxSafe(int row, int col, int num, int board[][9]){
	int rowStart = row - row%3;
	int colStart = col - col%3;
	for(int i = rowStart; i < rowStart+3; i++){
		for(int j = colStart; j < colStart + 3; j++){
			if(board[i][j] == num) return false;
		}
	}
	return true;
}

bool isColSafe(int col, int num, int board[][9]){
	for(int i = 0; i < 9; i++) if(board[i][col] == num) return false;
	return true;
}

bool isRowSafe(int row, int num, int board[][9]){
	for(int i = 0; i < 9; i++) if(board[row][i] == num) return false;
	return true;
}

bool can_place_num(int row, int col, int num, int board[][9]){
	if(!isRowSafe(row, num, board)) return false;
	if(!isColSafe(col, num, board)) return false;
	if(!isBoxSafe(row, col, num, board)) return false;
	return true;
}

bool sudokuSolver(int board[][9]){
    int row = -1;
    int col = -1;
    bool isEmpty = false;
    
  	//finding an empty cell
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if(isEmpty) break;
    }
    
    // if we could not find a empty cell, then the board is full
    if(row == -1) return true;
    
    for(int num = 1; num<=9; num++){
        if(can_place_num(row, col, num, board)){
            board[row][col] = num;
            if(sudokuSolver(board)) return true;
            else board[row][col] = 0;
        }
    }
    return false;
}


int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}



