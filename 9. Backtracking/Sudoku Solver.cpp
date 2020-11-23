

// https://www.codechef.com/CDMR2016/problems/SUDOKU

//Adam likes to solve mathematical puzzles and riddles. He is quite good in them. But he is new to Sudoku, he never solved it before. 
//Adam needs your help to solve Sudoku.
//
//Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so 
//that every row, column, and sub grid of size 3×3 contains exactly one instance of the digits from 1 to 9.
//
//Input
//Input contains 9 lines of 9 space separated digits from 0 to 9(0 denotes an empty space).
//
//Output
//Output contains 9 lines of 9 space separated digits from 1 to 9 which represent solution of Sudoku.
//
//Constraints
//Already mentioned above
//
//Example
//Input:
//  	
//  5 2 0 0 0 0 0 0 0
//  0 8 7 0 0 0 0 3 1
//  0 0 3 0 1 0 0 8 0
//  9 0 0 8 6 3 0 0 5
//  0 5 0 0 9 0 6 0 0
//  1 3 0 0 0 0 2 5 0
//  0 0 0 0 0 0 0 7 4
//  0 0 5 2 0 6 3 0 0
//
//
//Output:
//  3 1 6 5 7 8 4 9 2
//  5 2 9 1 3 4 7 6 8
//  4 8 7 6 2 9 5 3 1
//  2 6 3 4 1 5 9 8 7
//  9 7 4 8 6 3 1 2 5
//  8 5 1 7 9 2 6 4 3
//  1 3 8 9 4 7 2 5 6
//  6 9 2 3 5 1 8 7 4
//  7 4 5 2 8 6 3 1 9


#include<bits/stdc++.h>
using namespace std;

int board[9][9];
#define N 9

bool isBoxSafe(int row, int col, int num){
	int rowStart = row - row%3;
	int colStart = col - col%3;
	for(int i = rowStart; i < rowStart+3; i++){
		for(int j = colStart; j < colStart + 3; j++){
			if(board[i][j] == num) return false;
		}
	}
	return true;
}

bool isColSafe(int col, int num){
	for(int i = 0; i < N; i++) if(board[i][col] == num) return false;
	return true;
}

bool isRowSafe(int row, int num){
	for(int i = 0; i < N; i++) if(board[row][i] == num) return false;
	return true;
}

bool canPlaceNum(int row, int col, int num){
	if(!isRowSafe(row, num)) return false;
	if(!isColSafe(col, num)) return false;
	if(!isBoxSafe(row, col, num)) return false;
	return true;
}

bool sudokuSolver(){
	int row = -1, col = -1;
	bool isEmpty = false;
	
	// find empty cell in board
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j] == 0){
				row = i;
				col = j;
				isEmpty = true;
				break;
			}
		}
		if(isEmpty) break;
	}
	
	if(row == -1) return true; // meaning we couldnt find any empty cell
	
	for(int num = 1; num<=9; num++){
		if(canPlaceNum(row, col, num)){
			board[row][col] = num;
			if(sudokuSolver()) return true;
			else board[row][col] = 0;
		}
	}
	return false;
}

int main(){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int ele;
			cin>>ele;
			board[i][j] = ele;
		}
	}
	cout<<endl;
	
	if(sudokuSolver()){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cout<<board[i][j]<<" ";
		}
		cout<<endl;
		}
	}
	else cout<<"sudoku cant be solved";
	
	return 0;
}
