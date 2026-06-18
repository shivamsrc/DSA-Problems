#include<bits/stdc++.h>
using namespace std;

// Count Good Number (LC 1922) --> Given an integer n, return the total number of good digit strings of length n.

const long long MOD = 1e9 + 7;

void GN(long long n, int placeIdx, long long &ans){
    if(n==0){
        return;
    }

    // even index
    if(placeIdx % 2 == 0){
        ans = (ans * 5) % MOD;
    }
    else{
        ans = (ans * 4) % MOD;
    }

    GN(n-1, placeIdx+1, ans);
}

int countGoodNumbers(long long n) {
    long long ans = 1;

    GN(n, 0, ans);

    return ans;
}

// for Leetcode (without recursive approach though logic is quite similar)

long long power(long long base, long long exp){
    if(exp == 0) return 1;

    base = base % MOD;

    if(exp % 2 == 0){
        return power((base * base) % MOD, exp/2) % MOD;
    }

    return( base * power((base * base) % MOD, (exp-1)/2)) % MOD;
}

int countGoodNumbers2(long long n){
    long long oddPlace = n/2;
    long long evenPlace = n - oddPlace;

    long long oddWays = power(4, oddPlace);
    long long evenWays = power(5, evenPlace);

    return (oddWays * evenWays) % MOD;
}

int main(){
    cout<<power(5,2);

    return 0;
}