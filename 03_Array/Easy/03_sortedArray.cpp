#include<bits/stdc++.h>
using namespace std;

// check if the given array is sorted or not
bool check(vector<int>& nums) {
    int size = nums.size();
    bool sortedArr = true;

    for(int i=1; i<size; i++){
        if(nums[i]>nums[i-1]){
            sortedArr = false;
        }
    }

    return sortedArr;
}

// check if the given array is sorted or rotated, or not
// rotated - means only one point where there is deflection or conflict in sorting [5,6,7,8,1,2,3]
bool check2(vector<int>& nums) {
    int n = nums.size();
    int dropCount = 0;

    for(int i=0; i<n; i++){
        if(nums[i] > nums[(i+1)%n]){
            dropCount++;
        }
    }

    return dropCount <= 1;
}

int main(){
    vector<int> vec = {2,1,3,4};

    cout<<check2(vec);

    return 0;
}