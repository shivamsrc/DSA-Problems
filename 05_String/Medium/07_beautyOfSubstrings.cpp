#include<bits/stdc++.h>
using namespace std;

// Beauty of all substrings (LC 1781)
int beautySum(string s) {
    int n = s.size();
    int sum = 0;

    for(int i=0; i<n; i++){
        vector<int> vec(26);                   // given that string consists of only lowercase English letters.
        for(int j=i; j<n; j++){
            vec[s[j] - 'a']++;

            int highFreq = 0, lowFreq = INT_MAX;
            for(int k=0; k<vec.size(); k++){
                if(vec[k] > 0){
                    highFreq = max(highFreq, vec[k]);
                    lowFreq = min(lowFreq, vec[k]);
                }
            }

            sum += (highFreq - lowFreq);
        }
    }

    return sum;
        
}

int main(){
    string str = "aabcb";

    cout<<beautySum(str);

    return 0;
}