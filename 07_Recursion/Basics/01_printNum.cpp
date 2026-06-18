#include<bits/stdc++.h>
using namespace std;

// Print numbers from N to 1

void printNums(int n){
    if(n==1){
        cout<<n<<endl;
        return;
    }

    cout<<n<<endl;

    printNums(n-1);
}

// N factorial

int factorial(int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n-1);
}

// Sum of N to 1 numbers

int sum(int n){
    if(n==1){
        return 1;
    }

    return n + sum(n-1);
}

int main(){
    // printNums(10);

    // cout<<factorial(4);

    cout<<sum(5);

    return 0;
}