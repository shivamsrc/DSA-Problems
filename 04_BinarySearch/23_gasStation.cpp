#include<bits/stdc++.h>
using namespace std;

// Minimize max distance to gas station (Q20)

// Brute
long double minimiseMaxDistance3(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n-1, 0);                                      // a vector with the no. of gaps between each elements in the array. ex-> {1,13,17,23} so gap=3. initially all the gaps are 0 as no gas station is placed in those gaps. we'll increase the number as the no. of gas station between those gaps increases.

    
    for(int gasStation=0; gasStation <= k; gasStation++){            // this is to check the max gap currently and add an extra station between them
        long double maxSectionLen = -1;
        int maxInd = -1;                                             // this is for the first index of gap where the maximum lenth is present

        for(int i=0; i<n-1; i++){                                   // to find the maximum length and the initial index for that
            long double diff = arr[i+1] - arr[i];
            long double sectionLen = diff / ((long double)(howMany[i]+1));        // after adding or without any extra station
            if(sectionLen > maxSectionLen){
                maxSectionLen = sectionLen;
                maxInd = i;
            }
        }
        howMany[maxInd]++;                                             // at the end of the loop we'll find the maxSectionLen and the first index for that. ex-> {1,7} so here maxSectionLen=6 and firstIndex/maxInd = 0; 
    }

    long double maxAns = -1;
    for(int i=0; i<n-1; i++){                                           // this is to find the maximum distance with taking all the extra stations in consideration
        long double diff = arr[i+1] - arr[i];
        long double sectionLen = diff / ((long double)(howMany[i]+1));
        maxAns = max(maxAns, sectionLen);
    }

    return maxAns;
}

// Better
long double minimiseMaxDistance2(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    for(int i=0; i<n-1; i++){                                         // to keep all the sectionLengths along with their initial lengths
        pq.push({arr[i+1]-arr[i], i});
    }

    for(int gasStation=0; gasStation<=k; gasStation++){               // to insert the gap stations at the maxGaps and update the value in the priority_queue
        auto tp = pq.top();
        pq.pop();
        int secondInd = tp.second;

        howMany[secondInd]++;
        long double initLen = arr[secondInd+1] - arr[secondInd];
        long double newGapLen = initLen / (long double)(howMany[secondInd]+1);        // no. of section = gasStation+1
        pq.push({newGapLen, secondInd});
    }

    return pq.top().first;
}

// Optimal (similar to 14_nthRoot)
int numOfGasStationRequired(vector<int>& arr, long double assumedAns){
    int n = arr.size();
    int cnt = 0;

    for(int i=1; i<n; i++){
        int numInBetween = ((arr[i]-arr[i-1])/assumedAns);               // if we divide the gap with assumedAns then we'll get the no. of segment and since both are int so we'll get the floor value but if it's completely divisible then we'll get segments = no. of stations which isn't correct as no. of stations = segments - 1;
        if((arr[i]-arr[i-1]) / assumedAns == numInBetween * assumedAns){
            numInBetween--;
        }
        cnt += numInBetween;
    }

    return cnt;
}

long double minimiseMaxDistance(vector<int>& arr, int k){
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for(int i=0; i<n-1; i++){
        high = max(high, (long double)(arr[i+1]-arr[i]));
    }

    long double diff = 1e-6;

    while(high-low > diff){
        long double mid = low + (high-low)/(2.0);

        int requiredStation = numOfGasStationRequired(arr, mid);
        if(requiredStation > k){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    return high;
}

int main(){
    vector<int> arr = {1,13,17,23};

    cout<<minimiseMaxDistance(arr, 5);

    return 0;
}