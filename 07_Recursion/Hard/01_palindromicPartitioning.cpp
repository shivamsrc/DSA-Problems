#include<bits/stdc++.h>
using namespace std;

// Palindromic partitioning (LC 131)
// check notes and campare with the code and have dry run yourself and with chatgpt

bool isPalindrome(string &s){
    int left = 0;
    int right = s.size()-1;

    while(left < right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else{
            return false;
        }
    }

    return true;
}

void getAllPartitions(vector<vector<string>> &ans, vector<string> &temp, string s){
    if(s.size()==0){
        ans.push_back(temp);
        return;
    }

    for(int i=0; i<s.size(); i++){
        string part = s.substr(0, i+1);
        if(isPalindrome(part)){
            temp.push_back(part);
            getAllPartitions(ans, temp, s.substr(i+1));
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> temp;

    getAllPartitions(ans, temp, s);

    return ans;
}


int main(){
    string s = "aab";
    vector<vector<string>> ans = partition(s);

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}