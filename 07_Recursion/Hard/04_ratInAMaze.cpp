#include<bits/stdc++.h>
using namespace std;

// Rat in a Maze

void allPaths(vector<vector<int>> &mat, vector<string> &ans, int row, int col, string path){
    if(row < 0 || col < 0 || row >= mat.size() || col >= mat.size() || mat[row][col] == -1) return;        // boundary condition

    if(mat[row][col] == 0) return;

    if(row==mat.size()-1 && col==mat.size()-1){
        ans.push_back(path);
        return;
    }

    // we're at this cell now. mean visited
    mat[row][col] = -1;

    // making calls from this cell
    allPaths(mat, ans, row+1, col, path+"D");       // down
    allPaths(mat, ans, row-1, col, path+"U");       // up
    allPaths(mat, ans, row, col+1, path+"R");       // right
    allPaths(mat, ans, row, col-1, path+"L");       // left

    // we're leaving this cell. unvisit
    mat[row][col] = 1;

}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<string> ans;
    string path = "";

    allPaths(mat, ans, 0, 0, path);

    return ans;
}

int main(){
    vector<vector<int>> mat = {{1, 0, 0, 0} , {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = findPath(mat);
    for(auto it : ans){
        cout<<it<<endl;
    }

    return 0;
}