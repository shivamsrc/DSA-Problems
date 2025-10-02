#include<bits/stdc++.h>
using namespace std;

void IS(vector<int> &nums, int n){
    if(n >= nums.size()) return;

    for(int i=n; i>0; i--){
        if(nums[i] < nums[i-1]){
            swap(nums[i], nums[i-1]);
        }
    }

    IS(nums, n+1);
}

vector<int> insertionSort(vector<int>& nums) {
    IS(nums, 1);
    return nums;
}

int main(){
    vector<int> arr;
    arr.emplace_back(7);
    arr.emplace_back(4);
    arr.emplace_back(1);
    arr.emplace_back(5);
    arr.emplace_back(3);

    insertionSort(arr);

    for(auto it : arr){
        cout<<it<<" ";
    }

    return 0;
}