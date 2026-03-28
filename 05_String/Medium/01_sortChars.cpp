#include<bits/stdc++.h>
using namespace std;

// Sort characters by frequency (LC 451)

// Better
string frequencySort(string s) {
    int n = s.size();
    map<char, int> mp;
    
    for(int i=0; i<n; i++){
        mp[s[i]]++;
    }

    vector<pair<char,int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), [](pair<char, int> &p1, pair<char, int> &p2){
        return p1.second > p2.second;
    });

    int m = vec.size();
    string ans = "";

    for(int i=0; i<m; i++){
        for(int j=0; j<vec[i].second; j++){
            ans += vec[i].first;
        }
    }

    return ans;
}

// Optimal
string frequencySort2(string s){
    int n = s.size();

    vector<pair<char, int>> vec(123);                                 // size needs to be 123 as small 'z' is at index 122. given in question that string will contain only uppercase and lowercase letters. and the ascii value of small 'z' is at 122. till 122 all chars are included. we'll simply ignore the index at extra chars.

    for(int i=0; i<n; i++){
        int freq = vec[s[i]].second;
        vec[s[i]] = {s[i], freq+1};
    }

    sort(vec.begin(), vec.end(), [](pair<char, int> &p1, pair<char, int> &p2){
        return p1.second > p2.second;
    });

    string ans = "";

    for(int i=0; i<=122; i++){
        if(vec[i].second == 0) break;
        else{
            int freq = vec[i].second;
            char ch = vec[i].first;
            string temp = string(freq, ch);

            ans += temp;
        }
    }

    return ans;
}


int main(){
    string str = "tree";

    cout<<frequencySort2(str);

    return 0;
}