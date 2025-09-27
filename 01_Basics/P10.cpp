#include<bits/stdc++.h>
using namespace std;

// HASHING

// no. of times element appearing in an array
void frequencyCount(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin >> n;
    int arr[n];

    cout<<"Enter the values in array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // pre-computing
    int hashArr[13] = {0};                              // if max value of the element is 12
    for(int i=0; i<n; i++){
        hashArr[arr[i]] += 1;
    }

    //fetching
    int q;
    cout<<"how many elements frequency u wanna know ";
    cin>>q;
    while(q--){                                        // until 'q' becomes zero
        int num;
        cin>>num;
        cout<<"frequency: "<<hashArr[num]<<endl;
    }
}

// frequency of chars
void charHashing(){
    string s;
    cin >> s;

    // precomputing
    int hashArr[26] = {0};
    for(int i=0; i<s.length(); i++){
        hashArr[s[i] - 'a'] += 1;
    }

    // fetching
    int q;
    cout<<"how many chars freq u wanna know ";
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<"frequency: "<<hashArr[c - 'a']<<endl;
    }
}

// frequency of all chars
void allCharHash(){
    string s;
    cin >> s;

    // precomputing
    int hashArr[256] = {0};
    for(int i=0; i<s.length(); i++){
        hashArr[s[i]] += 1;
    }

    // fetching
    int n;
    cout<<"how many chars freq u wanna know: ";
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        cout<<"frequency : "<<hashArr[c]<<endl;
    }
}

// number hashing with map
void numHashingWithMap(){
    int n;
    cout<<"size of array ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // pre-computing
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    // fetching
    int q; 
    cout<<"how many nums freq u wanna know ";
    cin>>q;
    while(q--){
        int num;
        cin >> num;
        cout<<"frequency: "<<mp[num]<<endl;
    }
}

// problem LC: 1838
int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long left = 0;
    long long operations = 0;                                    // increment
    long long maxFreq = 1;                                      // max of no. of elements in the valid window

    for(int right = 1; right<nums.size(); right++){

        // operations required for incrementing all the element in the current window i.e, between left and right [left .... right]
        // How many additional operations are needed if I want to make all elements in my current window equal to the new target nums[right]
        operations += (long long) (nums[right] - nums[right-1]) * (right - left);     

        while(operations > k){                                  // if operations is greater then not possible to increment
            operations -= nums[right] - nums[left];             // Subtracts the increment cost that the leftmost element required to reach the current target nums[right].
            left++;                                             // removed the leftmost element from the window.
        }

        maxFreq = max(maxFreq, right-left+1);                   // +1 because right and left both are inclsive. ex-> [1,2,2] (indices 0 to 2) 2-0=2 but there are three elements so +1.
    }

    return maxFreq;
}

int main(){
    vector<int> v;
    v.emplace_back(3);
    v.emplace_back(4);
    v.emplace_back(4);
    v.emplace_back(5);
    v.emplace_back(10);

    cout<<maxFrequency(v, 5);

    return 0;
}