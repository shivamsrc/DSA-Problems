#include<bits/stdc++.h>
using namespace std;

// Maximum product sub-array
// find the subArray which has the maximum product of its elements and return the product

// Brute
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prod = INT_MIN;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int tempProd = 1;
            for(int k=i; k<=j; k++){
                tempProd = tempProd * nums[k];
                prod = max(tempProd, prod);
            }
        }
    }

    return prod;
}

// Better
int maxProduct2(vector<int>& nums){
    int n = nums.size();
    int prod = INT_MIN;

    for(int i=0; i<n; i++){
        int tempProd = nums[i];
        for(int j=i+1; j<n; j++){
            tempProd = tempProd * nums[j];
            prod = max(tempProd, prod);
        }
    }

    return prod;
}

// Optimal
int maxProduct3(vector<int>& nums){
    int n = nums.size();
    int pre = 1, suf = 1;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++){
        if(pre==0) pre=1;
        if(suf==0) suf=1;

        pre = pre * nums[i];
        suf = suf * nums[n-1-i];
        maxi = max(maxi, max(pre, suf));
    }

    return maxi;
}


int main(){
    vector<int> arr = {2,3,-2,4};

    cout<<maxProduct3(arr);

    return 0;
}