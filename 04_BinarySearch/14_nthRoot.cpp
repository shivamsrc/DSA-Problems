#include<bits/stdc++.h>
using namespace std;

// Nth Root of a Number Using Binary Search
// Square root, cube root, quadratic root

// for exact roots
int NthRoot(int N, int M) {                                 // Nth root of number M
    int low=1, high=M;
    int ans = -1;

    while(low<=high){
        long long mid = low + (high-low)/2;
        long long val = 1;
        for(int i=0; i<N; i++){
            val = val * mid;
        }

        if(val == M){
            return mid;
        }
        else if(val > M){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

// for decimal precision roots
void NthRoot2(int N, int M){
    double low = 1.0, high = M;
    double eps = 1e-6;                                      // 10^-6

    // we're basically reducing the range
    while((high-low) > eps){
        double mid = (high+low)/2.0;

        double val = 1.0;
        for(int i=0; i<N; i++){
            val = val * mid;
        }

        if(val > M){
            high = mid;
        }
        else{
            low = mid;
        }
    }

    cout<<low<<" "<<high;
}

int main(){
    NthRoot2(3, 9);

    return 0;
}