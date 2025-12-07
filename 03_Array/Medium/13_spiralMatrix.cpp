#include<bits/stdc++.h>
using namespace std;

// print the given matrix in spiral form

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();       // row
    int m = matrix[0].size();    // column
    vector<int> ans;
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    while(top <= bottom && left <= right){

        // left to right
        for(int i=left; i<=right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // top to bottom
        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // right to left
        if(top <= bottom){                                             // need to make sure that there is a row left to insert. didn't check for the upper two loops as they are already verififed throught the condition in the while loop.
            for(int i=right; i>= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // bottom to top
        if(left <= right){                                            // need to make sure that there is a column left to insert
            for(int i=bottom; i>=top; i--){ 
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;

}

int main(){
    vector<vector<int>> arr = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    vector<int> result = spiralOrder(arr);

    for(auto it : result){
        cout<<it<<" ";
    }

    return 0;
}