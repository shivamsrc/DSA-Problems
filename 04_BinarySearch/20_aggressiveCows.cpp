#include<bits/stdc++.h>
using namespace std;

// Aggressive Cows (Q17)

// Brute
bool canWePlace(vector<int>& nums, int k, int minConstraint){
    int n = nums.size();
    int lastPlaced = 0;                            // one cow is already placed at 0th index
    int cows = k-1;                                // same

    for(int i=1; i<n; i++){
        if(cows==0) return true;
        int dist = nums[i] - nums[lastPlaced];
        if(dist >= minConstraint){
            lastPlaced = i;
            cows--;
        }
    }

    if(cows==0) return true;
    return false;
}

int aggressiveCows2(vector<int>& nums, int k){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int high = nums[n-1] - nums[0];

    for(int i=1; i<=high; i++){
        if(canWePlace(nums, k, i) == true){
            continue;
        }
        else {
            return i-1;
        }
    }
}

// optimal
int aggressiveCows(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;

    int low = 1, high = nums[n-1] - nums[0];

    while(low<=high){
        int mid = low + (high-low)/2;

        if(canWePlace(nums, k, mid) == true){
            ans = mid;
            low = mid + 1;                                  // we need more max
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr= {0, 3, 4, 7, 9, 10};

    cout<<aggressiveCows2(arr, 4);

    return 0;
}