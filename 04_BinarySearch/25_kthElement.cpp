#include<bits/stdc++.h>
using namespace std;

// Find the Kth element of two sorted array
// similar logic as previous one

// Optimal
int kthElement(vector<int> &a, vector<int>& b, int k) {
    int n1 = a.size();
    int n2 = b.size();

    // high and low is representing how many elements we can choose from arr1

    int low = min(0, k-n2);                            // if in case, k=7 and n2=3 so doesn't matter what, we need to take 4 elements from arr1, that's the min. but if n2>k then the min can be 0 as we can take all the elemets from array2.
    int high = max(k, n1);

    int left = k;                                      // no. of element in left part
    int n = n1 + n2;

    while(low<=high){
        int cut1 = low + (high-low)/2;                                  // no. of elements taken from a
        int cut2 = left - cut1;                                         // elements taken from b

        int left1 = cut1==0 ? INT_MIN : a[cut1-1];
        int left2 = cut2==0 ? INT_MIN : b[cut2-1];

        int right1 = cut1==n1 ? INT_MAX : a[cut1];
        int right2 = cut2==n2 ? INT_MAX : b[cut2];

        if(left1 <= right2 && left2 <= right1){
            return max(left1, left2);
        }
        else if(left1 > right2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr1 = {1,3,5,7,9};
    vector<int> arr2 = {2,4,6,8,10};

    cout<<kthElement(arr1, arr2, 6);

    return 0;
}