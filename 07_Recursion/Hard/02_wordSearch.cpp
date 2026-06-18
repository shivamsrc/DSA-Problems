#include<bits/stdc++.h>
using namespace std;

// Word Search ( LC 79)

vector<vector<int>> directions = {
    {1, 0},          // down
    {-1, 0},         // up
    {0, 1},          // right
    {0, -1}          // left
};

int m, n;

bool find(vector<vector<char>>& board, string &word, int i, int j, int idx){
    if(word.size() == idx) return true;

    if(i<0 || j<0 || i>=m || j>=n || board[i][j] == '$') return false;

    if(board[i][j] != word[idx]) return false;

    char temp = board[i][j];
    board[i][j] = '$';                              // marked so same charcter on board can't be visited and counted in answer.

    for(auto &dir : directions){                     // we had found the correct letter now move in all the direction and find the next correct letter.
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if(find(board, word, new_i, new_j, idx+1)){
            return true;
        }
    }

    board[i][j] = temp;

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();

    // to traverse each word
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == word[0] && find(board, word, i, j, 0)){                     // if first letter found then
                return true;
            }
        }
    }

    return false;
}

int main(){
    vector<vector<char>> arr = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    string word = "SEE";

    cout<<exist(arr, word);


    return 0;
}