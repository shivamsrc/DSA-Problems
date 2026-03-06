#include<bits/stdc++.h>
using namespace std;

// Minimum Number of Days to Make m Bouquets

// Brute
int minDays2(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if((long long)m*k > n) return -1;                              // Impossible case - no. of flowers required to make the required no. of boquets are greater than total no. of flowers
    int minRange = *min_element(bloomDay.begin(), bloomDay.end());
    int maxRange = *max_element(bloomDay.begin(), bloomDay.end());

    for(int i=minRange; i<=maxRange; i++){                        // for each day
        int flowerCnt = 0;
        int possibleBqt = 0;
        for(int j=0; j<n; j++){                                  // checking no. of bloomed flowers by visiting each element in the array and no. of boquets possible
            if(bloomDay[j]<=i) flowerCnt++;
            else{
                possibleBqt += flowerCnt / k;
                flowerCnt = 0;
            }
        }
        possibleBqt += flowerCnt / k;
        if(possibleBqt >= m) return i;
    }

    return -1;
}

// Optimal
int possibleBqt(vector<int>& bloomDay, int k, int day){
    int n = bloomDay.size();
    int bloomedFlowers = 0;
    int possible = 0;

    for(int i=0; i<n; i++){
        if(bloomDay[i] <= day){
            bloomedFlowers++;
        }
        else{
            possible += bloomedFlowers/k;
            bloomedFlowers = 0;
        }
    }
    possible += bloomedFlowers/k;

    return possible;
}

int minDays(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    if(m*k > n) return -1;
    int minRange = *min_element(bloomDay.begin(), bloomDay.end());
    int maxRange = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = maxRange;

    int low = minRange, high = maxRange;

    while(low<=high){
        int mid = low + (high-low)/2;

        int possibleBqtNum = possibleBqt(bloomDay, k, mid);
        if(possibleBqtNum >= m){                                  // if this matches then it can also be true for elements in right and as we need in the min so we eliminate the right half and move to the left
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {7,7,7,7,12,7,7};

    cout<<minDays(arr, 2, 3);

    return 0;
}