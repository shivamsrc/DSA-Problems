#include<bits/stdc++.h>
using namespace std;

// left rotate an array by one place i.e, {1,2,3,4,5} --> {2,3,4,5,1}
vector<int> rotateByOne(vector<int>& nums){
    int size = nums.size();
    int temp = nums[0];

    for(int i=1; i<size; i++){
        nums[i-1] = nums[i];
    }
    nums[size-1] = temp;

    return nums;
}


int main(){
    vector<int> vec = {-1,-100,3,99};
    rotateByOne(vec);

    for(auto it : vec){
        cout<<it;
    }

    return 0;
}