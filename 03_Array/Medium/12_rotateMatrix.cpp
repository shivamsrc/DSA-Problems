#include<bits/stdc++.h>
using namespace std;

// Rotate matrix by 90 degree in clockwise direction

// Brute
vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    return ans;
}

// Optimal 
void rotate2(vector<vector<int>>& matrix){
    int n = matrix.size();

    // transposing the matrix 
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reversing each row
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int>> arr = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    // vector<vector<int>> result = rotate(arr);
    rotate2(arr);

    for(auto it : arr){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}