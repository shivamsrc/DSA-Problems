#include<bits/stdc++.h>
using namespace std;

int qS(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){                       // means they have not crossed each other
        
        while(arr[i] <= pivot && i<=high-1){       //finding element larger then pivot. so keep moving if arr[i] <= pivot and if any element is found greater then pivot then stop
            i++;
        }

        while(arr[j] > pivot && j>=low+1){       // finding element smaller than pivot.
            j--;
        }
        if(i<j){ 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(vector<int> &arr, int low, int high){

    if(low < high){                      // means there are more than one element in the array

        int partition = qS(arr, low, high);
        quickSort(arr, low, partition-1);
        quickSort(arr, partition+1, high);
    }
}

int main(){
    vector<int> nums;
    nums.emplace_back(4);
    nums.emplace_back(6);
    nums.emplace_back(2);
    nums.emplace_back(5);
    nums.emplace_back(7);
    nums.emplace_back(9);
    nums.emplace_back(1);
    nums.emplace_back(3);

    int n = nums.size();

    quickSort(nums, 0, n-1);

    for(auto it : nums){
        cout<<it<<" ";
    }

    return 0;
}