#include<bits/stdc++.h>
using namespace std;

// Median of two sorted arrays of different size.

// Brute
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> combinedArray;
    int ptr1=0, ptr2=0;

    while(ptr1<n1 || ptr2<n2){
        if(ptr1<n1 && ptr2<n2){
            if(nums1[ptr1]<nums2[ptr2]){
                combinedArray.push_back(nums1[ptr1]);
                ptr1++;
            }
            else{
                combinedArray.push_back(nums2[ptr2]);
                ptr2++;
            }
        }
        else if(ptr1<n1){
            combinedArray.push_back(nums1[ptr1]);
            ptr1++;
        }
        else{
            combinedArray.push_back(nums2[ptr2]);
            ptr2++;
        }
    }

    int n3 = combinedArray.size();
    double median;

    if(n3%2==0){
        int ptr = (n3-1)/2;
        median = (combinedArray[ptr] + combinedArray[ptr+1])/2.0;
    }
    else{
        int ptr = (n3-1)/2;
        median = combinedArray[ptr];
    }

    return median;
}

//  Better
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n3 = n1 + n2;

    int e1, e2;                                 // created two element to store the value of two middle digits
    int requiredElementInd = (n3-1)/2;

    int ptr1=0, ptr2=0;

    while(ptr1<n1 || ptr2<n2){
        if(ptr1<n1 && ptr2<n2){
            if(nums1[ptr1]<nums2[ptr2]){
                if((ptr1+ptr2)==requiredElementInd){
                    e1 = nums1[ptr1];
                }
                else if((ptr1+ptr2)==requiredElementInd+1){
                    e2 = nums1[ptr1];
                    break;
                }
                ptr1++;
            }
            else{
                if((ptr1+ptr2)==requiredElementInd){
                    e1 = nums2[ptr2];
                }
                else if((ptr1+ptr2)==requiredElementInd+1){
                    e2 = nums2[ptr2];
                    break;
                }
                ptr2++;
            }
        }
        else if(ptr1<n1){
            if((ptr1+ptr2)==requiredElementInd){
                e1 = nums1[ptr1];
            }
            else if((ptr1+ptr2)==requiredElementInd+1){
                e2 = nums1[ptr1];
                break;
            }
            ptr1++;
            
        }
        else{
            if((ptr1+ptr2)==requiredElementInd){
                e1 = nums2[ptr2];
            }
            else if((ptr1+ptr2)==requiredElementInd+1){
                e2 = nums2[ptr2];
                break;
            }
            ptr2++;
        }
    }

    double median;

    if(n3%2==0){
        median = (e1 + e2)/2.0;
    }
    else{
        median = e1;
    }

    return median;
}

// Optimal
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n2<n1) return findMedianSortedArrays(nums2, nums1);

    int low = 0;                                          // high and low is representing how many elements we can choose from arr1
    int high = n1;

    while(low<=high){
        int cut1 = low + (high-low)/2;                                  // mid
        int cut2 = ((n1+n2+1)/2) - cut1;

        int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
        int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];

        int right1 = cut1==n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2==n2 ? INT_MAX : nums2[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((n1+n2)%2==0){
                return (max(left1,left2)+min(right1,right2))/2.0;
            }
            else{
                return max(left1,left2);
            }
        }
        else if(left1 > right2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }

    return 0.0;

}

int main(){
    vector<int> arr1 = {1,2};
    vector<int> arr2 = {3,4};

    cout<<findMedianSortedArrays(arr1, arr2);

    return 0;
}