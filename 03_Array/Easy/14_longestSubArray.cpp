#include<bits/stdc++.h>
using namespace std;

// Longest sub array with given sum K (positive)

// Brute - find all the subArray and check them
int longestSubarray(vector<int> &nums, int k){
    int n = nums.size();
    int len = 0;

    for(int i=0; i<n; i++){                                   // keeping the first pointer

        for(int j=i; j<n; j++){                               // keeping the second pointer that starts from the first pointer

            int sum =0;
            for(int m = i; m<=j; m++){                      // finding the sum of elements between two pointers
                sum = sum + nums[m];
            }
            if(sum == k){
                len = max(len, j-i+1);                  // j index - i index + 1; +1 due to 0 based indexing
            }
        }
    }

    return len;
}

// Better - using hashMap
int longestSubarray2(vector<int>& nums, int k){
    int n = nums.size();
    map<int, int> mp;                                                // map<value, index>
    int maxLen = 0;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum = sum + nums[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);                                // i+1 because of 0 based indexing. 'sum' is the summation of all elements from 0 to i (current index)
        }
        int rem = sum - k;
        if(mp.find(rem) != mp.end()){                                // mp.find(rem) returns an iterator pointing to the map<rem,index> but if it doesn't found then it returns mp.end(). that maeans this will only execute if rem is found
            int len = i - mp[rem];                                   // map<value, index> so mp[value] = index; i (currentIndex) - mp[rem] (index j ) = length
            maxLen = max(maxLen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;                                             // creating a new element in the hash map. storing the sum from start index to current index i; so map[value] = index
        }
    }

    return maxLen;
}

// Optimal 
int longestSubarray3(vector<int>& nums, int k){
    int n = nums.size();
    int left = 0, right = 0;                            // two pointers
    int sum = nums[0];                                  // at the start, the sum is equals to the first element of the array
    int maxLen = 0;

    while(right < n){
        while(left <= right && sum > k){                    // keep trimmin only if the left pointer is still smaller compared to the right pointer and sum still exceedes the required sum 'k'
            sum = sum - nums[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if(right<n) sum = sum + nums[right];
    }

    return maxLen;
}

int main(){
    vector<int> arr = {10, 5, 2, 7, 1, 9, 1, 1, 1, 1};

    cout<<longestSubarray3(arr, 4);

    return 0;
}