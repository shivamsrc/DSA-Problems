#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    // loop for no. of steps (last element not sorting)
    for(int i=0; i<=n-2; i++){
        int mini = i;

        // loop to find the minimum element in the remaining part
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }

        // swapping
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;                                  // first element in the remainig part got the min value
    }
}

// selection sort with vector (same, no diff)
void selectionSort2(vector<int>& v){
    int n = v.size();

    for(int i=0; i<=n-2; i++){
        int mini = i;

        for(int j=i; j<=n-1; j++){
            if(v[j] < v[mini]){
                mini = j;
            }
        }

        int temp = v[mini];
        v[mini] = v[i];
        v[i] = temp;
    }
}

int main(){
    // int arr[6] = {13, 46, 24, 52, 20, 9};
    // selectionSort(arr, 6);

    // for(int i=0; i<6; i++){
    //     cout<<arr[i]<<" ";
    // }

    vector<int> v;
    v.emplace_back(13);
    v.emplace_back(46);
    v.emplace_back(24);
    v.emplace_back(52);
    v.emplace_back(20);
    v.emplace_back(9);
    selectionSort2(v);

    for(auto it : v){
        cout<<it<<" ";
    }
    
    return 0;
}