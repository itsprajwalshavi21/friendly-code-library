#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int board[9][9], int val){
	for(int i=0;i<9;i++){
		if(board[i][col] == val) return false;
		if(board[row][i] == val) return false;
		if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == val) return false;
	}
	
	return true;
}

bool isItSudoku(int board[9][9]) {
    // Write your code here.
// 	method-1
// 	int existInRow[9][9]={0}, existInCol[9][9]={0}, existInBox[9][9]={0};
        
// 	for(int i=0;i<9;i++){
// 		for(int j=0;j<9;j++){
// 			if(board[i][j] != 0){
// 				int num = board[i][j] - 1;
// 				int k = ((i/3) * 3) + (j/3);

// 				if(existInRow[i][num] || existInCol[j][num] || existInBox[k][num]){
// 					return false;
// 				}

// 				existInRow[i][num] = existInCol[j][num] = existInBox[k][num] = 1;
// 			}
// 		}
// 	}

// 	return true;
	
// 	method-2
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(board[i][j] == 0){
				for(int k=1;k<=9;k++){
					if(isSafe(i, j, board, k)){
						board[i][j]=k;
						if(isItSudoku(board)){
							return true;
						}else{
							board[i][j]=0;
						}
					}
				}
				return false;
			}
		}
	}
	
	return true;
}
