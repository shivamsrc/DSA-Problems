#include<bits/stdc++.h>
using namespace std;

// Word Break

bool help(string &s, vector<string>& wordDict, int i){
    if(i==s.size()) return true;

    for(auto word: wordDict){

        // if the addition of this word exceeds the length of the string then look for next word.
        if(i + word.size() > s.size()){
            continue;
        }

        bool match = true;

        // if the word length is not a concern then check if all the letters of word matches in the string from the index 'i'
        for(int j=0; j<word.size(); j++){
            if(s[i+j] != word[j]){
                match = false;
                break;
            }
        }

        // if match then call for checking word match for the remaining part
        if(match && help(s, wordDict, i+word.size())){
            return true;
        }
    }

    return false;
    
}

bool wordBreak(string s, vector<string>& wordDict) {
    return help(s, wordDict, 0);
}

int main(){
    vector<string> wordDict = {"takes" , "forward" , "you", "u"};

    cout<<wordBreak("takeuforward", wordDict);

    return 0;
}