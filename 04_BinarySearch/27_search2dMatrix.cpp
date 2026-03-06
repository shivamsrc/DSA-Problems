#include<bits/stdc++.h>
using namespace std;

// Search in 2D matrix

// solution (works for both LC & GFG)
bool bs(vector<int>& nums, int target){
    int m = nums.size();
    int low=0, high = m-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] == target){
            return true;
        }
        else if(nums[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return false;
}

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0; i<n; i++){
        bool ans = bs(matrix[i], target);

        if(ans) return true;
    }

    return false;
}


// solution (better - LC, Optimal - GFG)
bool searchMatrix2(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int i=0, j=m-1;                        // initially at top right corner

    while(i<n && j>=0){                         // as we are moving down the column so we must not go beyond the total no. of rows "n" otherwise it'll be out of bound. Similary, we're moving left in a row so we "j" must no go beyond 0 in left
        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] > target){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}

// solution (optimal - LC)
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n*m-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int row = mid/m;
        int col = mid%m;

        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> arr = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};

    cout<<searchMatrix(arr, 12);

    return 0;
}