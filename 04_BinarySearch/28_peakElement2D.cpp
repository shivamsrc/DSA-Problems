#include<bits/stdc++.h>
using namespace std;

// find the peak element in 2d array

// Optimal
int maxElement(vector<vector<int>>& mat, int col){
    int n = mat.size();           // row size

    int maxiRowInd = 0;
    int maxEl = mat[0][col];

    for(int i=0; i<n; i++){
        if(mat[i][col]>maxEl){
            maxEl = mat[i][col];
            maxiRowInd = i;
        }
    }

    return maxiRowInd;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low=0, high=m-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        int row = maxElement(mat, mid);                         // row index of max element in the 'mid' column

        int left = (mid-1)>=0 ? mat[row][mid-1] : -1;
        int right = (mid+1)<m ? mat[row][mid+1] : -1;

        if(mat[row][mid] > left && mat[row][mid] > right){
            return {row,mid};
        }
        else if(mat[row][mid] > right){               // right element in the row is smaller than current one so dec curve means peak is in the left
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return {-1,-1};
}

int main(){
    vector<vector<int>> arr = {{1,4}, {3,2}};

    vector<int> ans = findPeakGrid(arr);
    cout<<ans[0]<<endl;
    cout<<ans[1];

    return 0;
}