#include<bits/stdc++.h>
using namespace std;

// Reverse string - for char array (using two pointer approach) 
// tc -> o(n)
void reverseString(vector<char>& s) {
    int n = s.size();

    int left = 0, right = n-1;

    while(left<right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

//we can also use reverse function directly
// tc -> o(n)
void reverseString2(vector<char>& str){
    reverse(str.begin(), str.end());
}

int main(){
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    reverseString2(str);
    for(auto x : str){
        cout<<x<<" ";
    }
    cout<<endl;


    // we can directly reverse a string as well either using two pointer approach or reverse fuction
    string a = "work";
    reverse(a.begin(),a.end());
    cout<<a;

    return 0;
}