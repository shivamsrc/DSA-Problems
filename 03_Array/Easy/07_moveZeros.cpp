#include<bits/stdc++.h>
using namespace std;

// move zeros in an array at the end

// Brute force
void zeroesAtEnd(vector<int>& nums){
    int n = nums.size();
    vector<int> temp;

    for(int i=0; i<n; i++){
        if(nums[i] != 0){
            temp.emplace_back(nums[i]);
        }
    }

    for(int i=0; i<temp.size(); i++){
        nums[i] = temp[i];
    }

    for(int i=temp.size(); i<n; i++){
        nums[i] = 0;
    }
}

// Optimal Solution - using two pointer method
// firstly get the index of first 0
// start swapping from the next of that index

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = -1;

    for(int i=0; i<n; i++){                       // getting the index of first zero
        if(nums[i] == 0){
            j = i;
            break;
        }
    }

    if(j==-1) return;                              // if no zeros found

    for(int i=j+1; i<n; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}


int main(){
    vector<int> vec = {1,0,9,0,0,2,5,7,0,9};

    moveZeroes(vec);

    for(auto it : vec){
        cout<<it<<" ";
    }

    return 0;
}