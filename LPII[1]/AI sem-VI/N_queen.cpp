#include<iostream>
using namespace std;
#define N 4

bool isSafe(int board[N][N], int row, int col)
{
	for (int i = 0; i < col; i++){
		if (board[row][i])
			return false;
	}
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if (board[i][j])
			return false;
	}
	for (int i = row, j = col; j >= 0 && i < N; i++, j--){
		if (board[i][j])
			return false;
	}
	return true;
}

bool solveNQUtil(int board[N][N], int col)
{
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;

			board[i][col] = 0; 
		}
	}
	return false;
}

int main()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		cout<<("\n");
	}
	
	return 0;
}
