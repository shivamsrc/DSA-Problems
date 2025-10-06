#include<bits/stdc++.h>
using namespace std;

// Largest element in an array
int largestElement(vector<int>& nums) {
    int size = nums.size();
    int max = nums[0];

    for(int i=0; i<size-1; i++){
        if(nums[i]>max) max = nums[i];
    }
    return max;
}

int main(){
    vector<int> vec = {2, 3, 5, 5, 4};

    cout<<largestElement(vec);

    return 0;
}