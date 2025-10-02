#include<bits/stdc++.h>
using namespace std;

// merge the left and right side
void merge(vector<int> &arr, int low, int mid, int high){
    // for temporary storage
    vector<int> temp;

    int left = low;                           // points to the smallest element in the left sorted array
    int right = mid+1;                        // points to the smallest element in the right sorted array

    while(left<=mid && right<=high){         // when both the pointers are valid means elements are still left in both the sides
        if(arr[left] <= arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else{
            temp.emplace_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){                           // when the right side is exhausted means no element is there in the right side and some elements are still there in the left side.
        temp.emplace_back(arr[left]);
        left++;                                // moving the pointer in the left array 
    }

    while(right<=high){                         // when the left side is exhausted means no element is there in the left side and some elements are still there in the right side.
        temp.emplace_back(arr[right]);
        right++;
    }

    // updating the original array
    for(int i=low; i<=high; i++){
        arr[i] = temp[i - low];                 // every time temp will begin from '0' that's why so we made it 0,1,2,3,4,...
    }
}

// divide the array in left and right part
void mS(vector<int> &arr, int low, int high){
    // base condition - return when just single element is found
    if(low >= high) return;

    int mid = (low+high)/2;               // [low....mid]   [mid+1....high]

    mS(arr, low, mid);                    // further operation on left array
    mS(arr, mid+1, high);                 // further operation on right array
    merge(arr, low, mid, high);           // this merges the left and right sorted arrays in one sorted array
}

// handle the user's call
void mergeSort(vector<int> &arr, int n){
    mS(arr, 0, n-1);
}

int main(){
    vector<int> arr;
    arr.emplace_back(3);
    arr.emplace_back(1);
    arr.emplace_back(2);
    arr.emplace_back(4);
    arr.emplace_back(1);
    arr.emplace_back(5);
    arr.emplace_back(2);
    arr.emplace_back(6);
    arr.emplace_back(4);

    mergeSort(arr, 9);

    for(auto it : arr){
        cout<<it<<" ";
    }
}
