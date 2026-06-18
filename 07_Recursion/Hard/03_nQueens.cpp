#include<bits/stdc++.h>
using namespace std;

// N Queens problem (LC 51)

bool isSafe(vector<string> &board, int row, int col, int n){

    // horizontal
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q') return false;
    }

    // vertical
    for(int i=0; i<n; i++){
        if(board[i][col] == 'Q') return false;
    }

    // left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    if(row == n){
        ans.push_back(board);
        return;
    }

    // to visit each column of a row
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j, n)){
            board[row][j] = 'Q';
            nQueens(board, row+1, n, ans);                              // if queen is safe and placed in current row then trying for the next row.
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));                    // ["....", "....", "....", "...."] if n=4

    nQueens(board, 0, n, ans);                                  // n = size of board (n x n)

    return ans;
}

int main(){

    return 0;
}