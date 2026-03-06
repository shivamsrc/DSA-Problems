#include<bits/stdc++.h>
using namespace std;

// Find the row with maximum 1's

// Brute
int rrowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();                               // no. of rows
    int m = mat[0].size();                            // no. of columns

    int rowInd = -1;
    int maxCount = -1;

    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            cnt += mat[i][j];                         // if mat[i][j] is 0 then no effect otherwise count will increase by 1.
        }

        if(cnt > maxCount){
            rowInd = i;
            maxCount = cnt;
        }
    }

    return rowInd;
}

// Optimal
int lb(vector<int>& nums, int x){
    int m = nums.size();
    int low = 0, high = m-1;
    int ansIndex = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] >= x){
            ansIndex = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ansIndex;                               // in a normal lb if (there's no lb then we return the next hypothetical index but we'll not do that here)
}

int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int m = mat[0].size();

    int rowInd = -1;
    int maxCount = -1;

    for(int i=0; i<n; i++){
        int firstOccurance = lb(mat[i], 1);
        int cnt = m - firstOccurance;

        if(firstOccurance == -1) cnt = -1;

        if(cnt > maxCount){
            rowInd = i;
            maxCount = cnt;
        }
    }

    return rowInd;
}

int main(){
    vector<vector<int>> arr = {{0,0,1}, {0,1,1}, {1,1,1}};

    cout<<rowWithMax1s(arr);

    return 0;
}