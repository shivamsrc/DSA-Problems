#include<bits/stdc++.h>
using namespace std;

//  Median in a Row Wise Sorted Matrix

int ub(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int findSmallEqui(vector<vector<int>>& mat, int x){
    int n = mat.size();
    int m = mat[0].size();

    int cnt = 0;

    for(int i=0; i<n; i++){
        cnt += ub(mat[i], x);
    }

    return cnt;
}

int findMedian(vector<vector<int>>&matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = matrix[0][0], high = matrix[0][m-1];
    int required = (n*m)/2;

    for(int i=0; i<n; i++){
        if(matrix[i][0] < low) {
            low = matrix[i][0];
        }

        if(matrix[i][m-1] > high){
            high = matrix[i][m-1];
        }
    }

    while(low <=high){
        int mid = low + (high-low)/2;

        int smallerEqui = findSmallEqui(matrix, mid);

        if(smallerEqui <= required){                                        // required is the no. of element in the left side. so if the no. of element <= median is <= required then we need a bigger number because even if it's equal we need to look for an element whose no. of elements greater than median can be just more than required.
            low = mid + 1;
        }
        else{                                                               // else if it was more we'll need a small element as we are chaging for the first occurance
            high = mid - 1;
        }
    }

    return low;
}

int main(){
    vector<vector<int>> arr = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};

    cout<<findMedian(arr);

    return 0;
}