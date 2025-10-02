#include<bits/stdc++.h>
using namespace std;

void bS(vector<int> &nums, int n){
    if(n==1) return;

    // do adjacent swapping the push the biggest element to the last
    for(int i=0; i<n; i++){
        if(nums[i] > nums[i+1]){
            swap(nums[i], nums[i+1]);
        }
    }

    bS(nums, n-1);
}

vector<int> bubbleSort(vector<int>& nums) {
    bS(nums, nums.size()-1);
    return nums;
}

int main(){
    vector<int> arr;
    arr.emplace_back(7);
    arr.emplace_back(4);
    arr.emplace_back(1);
    arr.emplace_back(5);
    arr.emplace_back(3);

    bubbleSort(arr);

    for(auto it : arr){
        cout<<it<<" ";
    }

    return 0;
}