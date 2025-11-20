#include<bits/stdc++.h>
using namespace std;

// Max Consecutive Ones - in an array of element 0/1, find the highest no. of '1' appeared consecutively

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int temp=0;
    int maxCount=0;

    for(int i=0; i<n; i++){
        if(nums[i]==1){
            temp++;
            maxCount = max(temp, maxCount);
        }
        else{
            temp=0;
        }
    }

    return maxCount;
}

int main(){
    vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1};

    cout<<findMaxConsecutiveOnes(arr);

    return 0;
}