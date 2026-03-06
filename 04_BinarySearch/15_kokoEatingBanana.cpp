#include<bits/stdc++.h>
using namespace std;

// Koko eating banana

// Brute
long long timeCalc(vector<int>& piles, int bananas){                        // it calculates the total hours required to eat all the bananas given the no. of bananas/hr
    int n = piles.size();
    long long hrs = 0;
    for(int i=0; i<n; i++){
        hrs = hrs + ceil(piles[i]/double(bananas));
    }
    return hrs;
}

int minEatingSpeed2(vector<int>& piles, int h) {
    int n = piles.size();
    int maxElement = *max_element(piles.begin(), piles.end());

    for(int i=1; i<=maxElement; i++){                       // here 'i' is no. of bananas/hr. the range is (1 to max no of banana in the pile)
        int requiredHours = timeCalc(piles, i);
        if(requiredHours <= h){
            return i;
        }
    }

    return maxElement;
}

// Optimal
int minEatingSpeed(vector<int>& piles, int h){
    int n = piles.size();
    int maxElement = *max_element(piles.begin(), piles.end());
    int ans = maxElement;

    int low=1, high=maxElement;                        // range

    while(low<=high){
        int mid = low + (high-low)/2;
        long long totalHours = timeCalc(piles, mid);

        if(totalHours <= h){                                // if satisfied then we'll check for more minimum possibility
            ans = mid;
            high = mid-1;
        }
        else{                                               // here it means not satisfied so need to eat more bananas per hour
            low = mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,6,7,11};

    cout<<minEatingSpeed(arr, 8);

    return 0;
}