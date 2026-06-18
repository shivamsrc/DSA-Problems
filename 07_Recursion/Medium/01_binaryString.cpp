#include<bits/stdc++.h>
using namespace std;

// Generate Binary Strings Without Consecutive 1s --> Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

void BS(int idx, vector<string> &ans, string &temp, int n){
    if(idx == n){
        ans.push_back(temp);
        return;
    }

    temp.push_back('0');
    BS(idx+1, ans, temp, n);
    temp.pop_back();

    if(temp.empty() || temp.back() != '1'){
        temp.push_back('1');
        BS(idx+1, ans, temp, n);
        temp.pop_back();
    }
}

vector<string> generateBinaryStrings(int n) {
    vector<string> ans;

    string temp;

    BS(0, ans, temp, n);

    return ans;
}

int main(){
    vector<string> ans = generateBinaryStrings(4);

    for(auto it : ans){
        for(auto x : it){
            cout<<x;
        }
        cout<<endl;
    }

    return 0;
}