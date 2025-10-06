#include<bits/stdc++.h>
using namespace std;

// remove dublicate elements from a given sorted array
// return the no. of unique elements 
// also return the array with the unique elements coming first.

// Brute force approach
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    set<int> s;
    int index = 0;

    for(int i=0; i<n; i++){
        s.insert(nums[i]);
    }

    for(auto it : s){
        nums[index] = it;
        index++;
    }

    return index;
}

// Optimal Solution
int removeDuplicates2(vector<int>& nums){
    int n = nums.size();
    int i=0;

    for(int j=1; j<n; j++){
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }

    return i+1;
}

int main(){
    vector<int> vec = {-2, 2, 4, 4, 4, 4, 5, 5};

    cout<<removeDuplicates2(vec);

    return 0;
}