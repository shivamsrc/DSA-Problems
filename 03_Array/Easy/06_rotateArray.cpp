#include<bits/stdc++.h>
using namespace std;

// rotate the array to the right by k steps, where k is non-negative. 

// Brute force method
void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    if(k==0) return;
    k = k % size;                       // if size is 7 and k=8 this means one full rotation means everything is back to normal and then one rotation.
    vector<int> arr(k);

    for(int i=0; i<k; i++){
        arr[i]=nums[size-k+i];          // i=0,1,2,... (storing the nums that are getting taken from the last to be placed at first)
    }
    for(int i=size-1; i>=k; i--){       // replacing the elements in nums from last (means putting the new elements from last like nums[7] = nums[4])
        nums[i] = nums[i-k];
    }
    for(int i=0; i<k; i++){
        nums[i] = arr[i];
    }
}


// optimal - no extra space

void reverseIt(vector<int>& nums, int start, int end){
    while(start<end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate2(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;
    if(k==0) return;
    reverseIt(nums, 0, n-k-1);                   // can directly use reverse() as well
    reverseIt(nums, n-k, n-1);
    reverseIt(nums, 0, n-1);
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    rotate2(vec, 3);

    for(auto it : vec){
        cout<<it<<" ";
    }

    return 0;
}