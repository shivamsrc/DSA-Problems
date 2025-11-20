#include<bits/stdc++.h>
using namespace std;

// missing number problem - if N=5 and 4 nums are given then find the missing number between 1-5.
// array is not necessarly sorted.

// Brute
int missingNumber(vector<int>& nums){
    int n = nums.size();

    for(int i=0; i<=n; i++){
        int flag=0;

        for(int j=0; j<n; j++){
            if(nums[j]==i){                       // means that if number is found then break and check for the next one
                flag=1;
                break;
            }
        }

        if(flag==0){                             // flag will remain '0' if number doesn't match then return that number
            return i;
        }
    }
}

// Better
int missingNumber2(vector<int>& nums){
    int n = nums.size();
    vector<int> hash(n+1);                      // creating a vector of size that's (+1) of the size of the given array

    for(int i=0; i<n; i++){
        hash[nums[i]] = 1;                      // hash[nums[i]] = hash[3] = 1; and similarly others...
    }

    for(int i=0; i<n; i++){
        if(hash[i]==0){                         // now check which hash element is not marked 1
            return i;
        }
    }
}

// Optimal - sum method.
int missingNumber3(vector<int>& nums){
    int n = nums.size();

    // calulatin the sum of first 'n' natural nums
    int sum1 = (((n+1)*(n+2))/2);
    int sum2 = 0;

    // calculating the sum of elements in the vector
    for(int i=0; i<n; i++){
        sum2 = sum2 + nums[i];
    }

    return (sum1 - sum2);
}

// Optimal - XOR method
int missingNumber4(vector<int>& nums){
    int n = nums.size();
    int N = n+1;                  // size of the array without missing element

    int xor1=0;
    int xor2=0;

    for(int i=0; i<n; i++){
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i+1);                                    // xor1 goal is to get xored with all the numbers in the original array
    }
    xor1 = xor1 ^ N;

    return (xor1 ^ xor2);
}

// XOR method for 0-n
int missingNumber5(vector<int>& nums){
    int n = nums.size();
    int N = n+1;

    int xor1 = n;
    int xor2 = 0;

    for(int i=0; i<n; i++){
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ i;
    }

    return xor1 ^ xor2;
}

int main(){
    vector<int> arr = {0, 1, 2, 4, 5};

    cout<<missingNumber5(arr);

    return 0;
}