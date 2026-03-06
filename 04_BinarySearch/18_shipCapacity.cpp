#include<bits/stdc++.h>
using namespace std;

// Find the least weight capacity of the ship to ship packages within given days

// Brute
int daysNeeded(vector<int>& weights, int capacity){
    int n = weights.size();
    int calcDays = 0;
    int cap = capacity;
    for(int i=0; i<n; i++){
        if(weights[i] > cap){
            cap = capacity;
            calcDays++;
        }
        cap -= weights[i];
    }
    calcDays += 1;

    return calcDays;
}

int shipWithinDays2(vector<int>& weights, int days) {
    int n = weights.size();
    int totalSum = accumulate(weights.begin(), weights.end(), 0LL);
    int maxElement = *max_element(weights.begin(), weights.end());              // doesn't matter the day, the maxElement should be the least capacity in the range otherwise the heaviest material can never be transported if the capacity is lower than that.
    int ans = totalSum;

    for(int i=maxElement; i<=totalSum; i++){
        int dayCheck = daysNeeded(weights, i);

        if(dayCheck <= days) return i;
    }

    return totalSum;
}

// Optimal
int shipWithinDays(vector<int>& weights, int days){
    int n = weights.size();
    int totalSum = accumulate(weights.begin(), weights.end(), 0);
    int maxElement = *max_element(weights.begin(), weights.end());
    int ans = totalSum;

    int low=maxElement, high=totalSum;

    while(low<=high){
        int mid = low + (high-low)/2;

        int dayCheck = daysNeeded(weights, mid);
        if(dayCheck <= days){
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
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    cout<<shipWithinDays(arr, 5);

    return 0;
}