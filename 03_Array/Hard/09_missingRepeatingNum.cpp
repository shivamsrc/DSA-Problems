#include<bits/stdc++.h>
using namespace std;

// find the missing and the repeating number 

// Brute
vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();
    int missingNum = -1, repeatingNum = -1;
    vector<int> ans;

    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(i==nums[j]) count++;
        }
        if(count==0) missingNum = i;
        else if(count==2) repeatingNum = i;

        if(missingNum != -1 && repeatingNum != -1) break;
    }

    ans.push_back(repeatingNum);
    ans.push_back(missingNum);

    return ans;
}

// Better (using hashing)
vector<int> findMissingRepeatingNumbers2(vector<int> nums){
    int n = nums.size();
    int repeatingNum = -1, missingNum = -1;
    vector<int> ans;
    vector<int> hashArr(n+1);                                  // need index till 'n' so the size has to be n+1 due to zero based indexing

    for(int i=0; i<n; i++){
        hashArr[nums[i]]++;
    }

    for(int i=1; i<=n; i++){
        if(hashArr[i]==0) missingNum = i;
        else if(hashArr[i]==2) repeatingNum = i;

        if(repeatingNum != -1 && missingNum != -1) break;
    }

    ans.push_back(repeatingNum);
    ans.push_back(missingNum);

    return ans;
}

// Optimal - Math
vector<int> findMissingRepeatingNumbers3(vector<int> nums){
    int n = nums.size();
    vector<int> ans;
    long long sumG=0, sumSqrG=0;                          // sum of given numbers; sum of square of given numbers

    long long sumN = ((long long)n * (n+1))/2;                      // sum of first n natural numbers
    long long sumSqrN = (((long long)n * (n+1) * (2*n + 1))/6);     // sum of square of first n natural numbers

    for(int i=0; i<n; i++){
        sumG = sumG + nums[i];
        sumSqrG = sumSqrG + ((long long)nums[i] * nums[i]);
    }

    long long val1 = sumG - sumN;                     // x - y
    long long val2 = sumSqrG - sumSqrN;               // (x-y)(x+y)
    val2 = val2 / val1;                         // x + y

    long long x = (val1 + val2)/2;                    // (x-y)+(x+y) = val1 + val2 ==> 2x = val1 + val2  ==> x = (val1+val2)/2
    long long y = x - val1;                           // x-y = val1; 

    ans.push_back((int)x);
    ans.push_back((int)y);

    return ans;
}

// Optimal - xor
vector<int> findMissingRepeatingNumbers4(vector<int> nums){
    int n = nums.size();
    int xr = 0;

    for(int i=0; i<n; i++){                           // taking the xor of all the numbers in the given array and the first n natural numbers.
        xr = xr ^ nums[i];
        xr = xr ^ (i+1);
    }

    int bitNo = 0;
    while(true){
        if((xr & (1 << bitNo)) != 0){                   // AND with other numbers will give (0 0 0) but with the same number it will give that number
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;
    for(int i=0; i<n; i++){
        // part of 1 club
        if((nums[i] & (1<<bitNo)) != 0){
            one = one ^ nums[i];
        }
        // part of zeroth club
        else{
            zero = zero ^ nums[i];
        }
    }

    for(int i=1; i<=n; i++){
        // part of 1 club
        if((i & (1<<bitNo)) != 0){
            one = one ^ i;
        }
        // part of zeroth club
        else{
            zero = zero ^ i;
        }
    }

    // now just confirming which one is repeating number and which one is missing
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i] == zero) cnt++;
    }

    if(cnt==2) return {zero, one};
    return {one, zero};
}

int main(){
    vector<int> arr = {4,3,6,2,1,1};

    vector<int> result = findMissingRepeatingNumbers3(arr);

    for(auto it : result){
        cout<<it<<" ";
    }

    return 0;
}