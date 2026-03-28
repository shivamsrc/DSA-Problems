#include<bits/stdc++.h>
using namespace std;

// repeated string match --> there are two strings given, 'a' and 'b'. return the minimum number of times we have to repeat string 'a' so that string 'b' becomes its substring. if it is not possible then return -1

int repeatedStringMatch(string a, string b) {
    int n = a.size();
    int m = b.size();

    string aRepeat = "";
    int count = 0;

    // minimum repeatation
    while(aRepeat.size() < m){
        aRepeat += a;
        count++;
    }

    // 2 more repeatation for safety
    for(int i=0; i<=2; i++){
        int found = aRepeat.find(b);
        if(found != string::npos) return count;
        else{
            aRepeat += a;
            count ++;
        }
    }

    return -1;
}

int main(){
    string a = "a", b = "aa";

    cout<<repeatedStringMatch(a, b);

    return 0;
}