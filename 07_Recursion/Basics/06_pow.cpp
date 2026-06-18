#include<bits/stdc++.h>
using namespace std;

// pow(x, n) = x^n (LC 50)

double solve(double x, long n){
    if(n == 0){
        return 1;
    }

    // negative power case
    if(n < 0){
        return solve(1/x, -n);
    }

    // even case
    if(n % 2 == 0){
        return solve(x*x, n/2);
    }

    return x*solve(x*x, (n-1)/2);        // odd case
}

double myPow(double x, int n) {
    
    return solve(x, (long)n);
}

int main(){
    cout<<myPow(2.00000, -2);

    return 0;
}