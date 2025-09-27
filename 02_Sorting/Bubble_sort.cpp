#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    // loop for each step - sorting for each of the remaining part
    for(int i=n-1; i>=0; i--){
        bool didSwap = 0;
        // adjacent comparison and swapping
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0){
            break;
        }
    }
}

vector<int> bubbleSort2(vector<int>& nums) {
        int n = nums.size();

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<i; j++){                   // j<i and not '=' because we can be at nums[last] and check for nums[last+1];
                if(nums[j] > nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }

        return nums;
}

int main(){
    int arr[6] = {13, 46, 24, 52, 20, 9};
    bubbleSort(arr, 6);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }

    // vector<int> v;
    // v.emplace_back(7);
    // v.emplace_back(4);
    // v.emplace_back(1);
    // v.emplace_back(5);
    // v.emplace_back(3);

    // bubbleSort2(v);

    // for(auto it : v){
    //     cout<<it<<" ";
    // }

    return 0;
}