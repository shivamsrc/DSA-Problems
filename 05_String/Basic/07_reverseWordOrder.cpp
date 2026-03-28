#include<bits/stdc++.h>
using namespace std;

// Reverse Words in a string (LC 151) --> Given an input string s, reverse the order of the words. s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Using stringstream() - it tokenize the sentence based on spaces.
string reverseWords2(string s) {
    int n = s.size();

    stringstream ssfunc(s);
    string token = "";
    string result = "";

    while(ssfunc >> token){                              // stringstring by default will tokenize the sentence based on spaces. in each iteration we are getting a new tokenized word that we are putting in the token
        result = token + " " + result;
    }

    return result.substr(0, result.size()-1);            // substr(index, lenght)
}


// Using two pointer approach
string reverseWords(string s){
    int n = s.size();

    reverse(s.begin(), s.end());

    int i = 0;

    // main ptr responsible for reversing indivisual words
    int l = 0, r = 0;

    while(i < n){
        while(i < n && s[i] != ' '){
            s[r] = s[i];
            r++;
            i++;
        }

        if(l<r){
            reverse(s.begin()+l, s.begin()+r);                 // reversingn an indivisual word

            s[r] = ' ';
            r++;                                               // new start positon for another word
            l = r;
        }

        i++;
    }

    s = s.substr(0, r-1);                                      // let say sentence ended at index=13 but due to one space and increment, 'r' is at index=15. so now we need to give the length of substr which is 14 so r-1.

    return s;
}


int main(){
    string str = "i am a boy";

    cout<<reverseWords(str);

    return 0;
}