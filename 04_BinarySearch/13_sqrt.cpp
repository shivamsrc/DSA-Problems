#include<bits/stdc++.h>
using namespace std;

// Find the square root of an integer

// Brute
int floorSqrt2(int n)  {
    int ans = 1;
    for(int i=1; i<=n; i++){
        if(i*i <= n){
            ans =  i;
        }
        else break;
    }

    return ans;
}

// Optimal
int floorSqrt(int n){
    int low = 1, high = n;
    int ans = 1;

    while(low<=high){
        long long mid = low + (high-low)/2;
        long long val = mid*mid;

        if(val > n){
            high = mid - 1;
        }
        else{
            ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    cout<<floorSqrt(37);

    return 0;
}