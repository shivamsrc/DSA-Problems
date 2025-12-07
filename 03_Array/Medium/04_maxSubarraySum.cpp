#include<bits/stdc++.h>
using namespace std;

// Maximum sub array sum - given an array that has both positive and negative values, give the sub array (sum of that subArray not subArray) whose sum will be maximum

// Brute - iterate through all the sub arrays
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i=0; i<n; i++){                                           // 'i' is acting as the head

        for(int j=i; j<n; j++){                                      // from head to the end

            int sum = 0;

            for(int k=i; k<=j; k++){                                 // a new sub array is formed due to the inclusion of a new element in the sub array so now adding all the elements
                sum = sum + nums[k];
            }
            maxi = max(sum, maxi);
        }
    }

    return maxi;
}

// Better -
int maxSubArray2(vector<int>& nums){
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i=0; i<n; i++){

        int sum = 0;
        for(int j=i; j<n; j++){
            sum = sum + nums[j];
            maxi = max(sum, maxi);
        }
    }

    return maxi;
}

// Optimal - kadane's algorith
int maxSubArray3(vector<int>& nums){
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;

    for(int i=0; i<n; i++){
        if(sum<0) sum=0;

        sum = sum + nums[i];
        maxi = max(maxi, sum);
    }

    return maxi;
} 

// Optimal (but returns the subArray itself)
vector<int> maxSubArray4(vector<int>& nums){
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1, ansEnd = -1;
    int start;

    for(int i=0; i<n; i++){
        if(sum == 0) start = i;

        sum = sum + nums[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start, ansEnd = i;
        }

        if(sum<0){
            sum = 0;
        }
    }

    return {ansStart, ansEnd};
}

int main(){
    vector<int> arr = {2, 3, 5, -2, 7, -4};

    cout<<maxSubArray3(arr);

    return 0;
}