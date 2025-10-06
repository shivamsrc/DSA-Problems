#include<bits/stdc++.h>
using namespace std;

// Find the second largest element in array

// Brute force approach
int secondLargestElement(vector<int>& nums) {
    int size = nums.size();

    sort(nums.begin(), nums.end());
    int secondL = -1;

    for(int i=size-1; i>=0; i--){
        if(nums[i]<nums[size-1]){
            secondL = nums[i];
            break;
        }
    }

    return secondL; 
}

// Better solution - find the largest and then loop backward and find the element smaller than the largest
int secondLargestElement2(vector<int>& nums){
    int size = nums.size();
    int largest = nums[0];
    int secondL = -1;

    for(int i=0; i<size; i++){
        if(nums[i]>largest){
            largest = nums[i];
        }
    }

    for(int i=0; i<size; i++){
        if(nums[i]>secondL && nums[i]<largest){
            secondL = nums[i];
        }
    }

    return secondL;
}

// Optimal solution - if largest changes then the secondL becomes the largest
int secondLargestElement3(vector<int>& nums){
    int size = nums.size();
    int largest = nums[0];
    int secondL = -1;

    for(int i=0; i<size; i++){
        if(nums[i]>largest){
            secondL = largest;
            largest = nums[i];
        }
        else if(nums[i]>secondL && nums[i]<largest){
            secondL = nums[i];
        }
    }

    return secondL;
}

// Second Smallest
int secondSmallest(vector<int>& nums){
    int size = nums.size();
    int smallest = INT_MAX;
    int secondSmall = INT_MAX;

    for(int i=0; i<size; i++){
        if(nums[i]<smallest){
            secondSmall = smallest;
            smallest = nums[i];
        }
        else if(nums[i]>smallest && nums[i]<secondSmall){
            secondSmall = nums[i];
        }
    }

    return secondSmall;
}

int main(){
    vector<int> vec = {2, 1, 3, 5, 5, 4};

    cout<<secondSmallest(vec);
    
    return 0;
}