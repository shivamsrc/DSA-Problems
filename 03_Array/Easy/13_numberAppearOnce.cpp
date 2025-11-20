#include<bits/stdc++.h>
using namespace std;

// find the number that appears just once where rest of the numbers are appearing twice

// Brute 
int singleNumber(vector<int>& nums){
    int n = nums.size();

    for(int i=0; i<n; i++){
        int num = nums[i];
        int count = 0;

        for(int j=0; j<n; j++){
            if(num == nums[j]){
                count++ ;
            }
        }
        if(count==1){
            return num;
        }
    }
}

// Better
int singleNumber2(vector<int>& nums){
    int n = nums.size();

    int maxi = nums[0];                                  // finding the maximum num so that we can create an array of that size
    for(int i=0; i<n; i++){
        maxi = max(maxi, nums[i]);
    }

    vector<int> hash(maxi+1);                              // creating a hash array where we'll be increasing the value at a particular index based on the no. of time that number is appearing. hash[nums[i]]++;
    for(int i=0; i<n; i++){
        hash[nums[i]]++;
    }

    for(int i=0; i<n; i++){                               // finding the hash index at which the value is one.
        if(hash[nums[i]] == 1){
            return nums[i];
        }
    }
}

// Better using map
int singleNumber3(vector<int>& nums){
    int n = nums.size();
    map<long long, int> mp;                             // map<index, value> in case if there are many numbers so index can be really big even if the no. stored in them are small.

    for(int i=0; i<n; i++){
        mp[nums[i]]++;
    }

    for(auto it : mp){
        if(it.second == 1){
            return it.first;
        }
    }
}

// Optimal using XOR
int singleNumber4(vector<int>& nums){
    int n = nums.size();
    int Xor = 0;

    for(int i=0; i<n; i++){
        Xor = Xor ^ nums[i];
    }

    return Xor;
}

int main(){
    vector<int> arr = {1,1,2,2,3,4,4,5,5};

    cout<<singleNumber4(arr);

    return 0;
}