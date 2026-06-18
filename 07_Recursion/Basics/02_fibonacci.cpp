#include<bits/stdc++.h>
using namespace std;

// Fibonacci Series (return nth term)

int fib(int n){
    if(n==0 || n==1) return n;

    return fib(n-1)+fib(n-2);
}

// Check if array is sorted using recursion. here 'n' is the size if the array

bool isSorted(vector<int> arr, int n){
    if(n==1) return true;

    bool ans = arr[n-1] >= arr[n-2];

    return ans ? isSorted(arr, n-1) : ans;
}

// Recursive Binary Search

int BS(vector<int> arr, int target, int low, int high){
    if(low > high) return -1;

    int mid = (low + high)/2;

    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) return BS(arr, target, low, mid-1);
    return BS(arr, target, mid+1, high);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};

    cout<<BS(arr, 7, 0, arr.size()-1);

    return 0;
}