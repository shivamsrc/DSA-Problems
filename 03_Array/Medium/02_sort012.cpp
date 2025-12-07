#include<bits/stdc++.h>
using namespace std;

// sort an array of 0's, 1's and 2's

// Better
void sortZeroOneTwo(vector<int>& nums) {
    int n = nums.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    // counting the numbers of 0,1,2
    for(int i=0; i<n; i++){
        if(nums[i]==0) count0++;
        else if(nums[i]==1) count1++;
        else count2++;
    }

    // replacing the numbers based on their count - this whole take just o(n)
    for(int i=0; i<count0; i++) nums[i]=0;
    for(int i=count0; i<count0+count1; i++) nums[i]=1;
    for(int i=count0+count1; i<count0+count1+count2; i++) nums[i]=2;
}

// Optimal - Dutch national flag algorith
void sortZeroOneTwo2(vector<int>& nums){
    int n = nums.size();
    int low=0, mid=0, high=n-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


int main(){
    vector<int> arr = {1,2,0,0,1,1,2,0,1};

    sortZeroOneTwo2(arr);

    for(auto it : arr){
        cout<<it<<" ";
    }

    return 0;
}