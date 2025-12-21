#include<bits/stdc++.h>
using namespace std;

// Merge 2 sorted array in a way that the two arrays are sorted compared to the merged array

// Brute
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums3(m+n);
    int ptr1 = 0;                                // pointer for first array
    int ptr2 = 0;                                // pointer for second array
    int index = 0;                               // index for the third array (extra array to solve the problem)

    while(ptr1 < m && ptr2 < n){
        if(nums1[ptr1] < nums2[ptr2]){
            nums3[index] = nums1[ptr1];
            ptr1++; index++;
        }
        else{
            nums3[index] = nums2[ptr2];
            ptr2++; index++;
        }
    }

    while(ptr1 < m){
        nums3[index] = nums1[ptr1];
        index++; ptr1++;
    }

    while(ptr2 < n){
        nums3[index] = nums2[ptr2];
        index++; ptr2++;
    }

    // changing or sorting the given main two arrays
    for(int i=0; i<m+n; i++){
        if(i<m) nums1[i] = nums3[i];
        else nums2[i-m] = nums3[i];                                   // i-n => 4-4=0; 5-4=1; 6-4=2; etc..
    }
}

// Better (optimal-1)
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int left = m-1;                        // biggest element in array1
    int right = 0;                         // smallest element in array2

    while(left >=0 && right < n){               // sending all the smallest element in the first array and the bigger one in the second array though they will not be in the correct order but we can sort them later
        if(nums1[left] > nums2[right]){
            swap(nums1[left], nums2[right]);
            left--; right++;
        }
        else{
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

// Optimal-2
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int len = (m+n);
    int gap = (len/2) + (len%2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right < len){
            // arr1 & arr2
            if(left < m && right >= m){
                if(nums1[left] > nums2[right-m]){                             // here right ptr is in the second array but it's based on full length so we can make it compatible for nums2 index by substracting 'n'
                    swap(nums1[left], nums2[right-m]);
                }
            }
            // arr2 & arr2
            else if(left >=m){
                if(nums2[left-m] > nums2[right-m]){                            // both ptr is in the second array so we have to make both of them suitable for the indexing of the nums2
                    swap(nums2[left-m], nums2[right-m]);
                }
            }
            // arr1 & arr1
            else{
                if(nums1[left]>nums1[right]){
                    swap(nums1[left], nums1[right]);
                }
            }
            left++; right++;
        }

        if(gap == 1) break;
        else gap = (gap/2) + (gap%2);
    }
}

// LC PS-88 (TC -> O(m+n))
void merge4(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int left = m-1;
    int right = n-1;
    int len = m+n-1;

    while(left >= 0 && right >= 0){
        if(nums2[right] >= nums1[left]){
            nums1[len] = nums2[right];
            len--; right--;
        }
        else{
            nums1[len] = nums1[left];
            len--; left--;
        }
    }

    while(right>=0){
        nums1[len] = nums2[right];
        len--; right--;
    }
}

int main(){
    vector<int> arr1 = {1,2,3,0,0,0};
    vector<int> arr2 = {2,5,6};

    merge4(arr1, 3, arr2, 3);

    for(auto it : arr1){
        cout<<it<<" ";
    }
    // cout<<endl;
    // for(auto it : arr2){
    //     cout<<it<<" ";
    // }

    return 0;
}