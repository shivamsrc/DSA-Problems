#include<bits/stdc++.h>
using namespace std;

// sort() function

// using directly 
void explainSort(){
    vector<int> v;

    v.push_back(30);
    v.push_back(12);
    v.push_back(19);
    v.push_back(5);
    v.emplace_back(13);

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    sort(v.begin(), v.end());                          // sort[start, end)

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;


    // sroting in descending order
    sort(v.begin(), v.end(), greater<int>());                          // sort[start, end)

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;


    // sroting between few numbers rather than whole
    sort((v.begin())+1, (v.begin())+4);                          // sort[start, end)

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
}

// using own sorting mechanism
bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.first > p2.first) return true;
    return false;
}

void explainSortOwn(){
    // sort it according to second element
    // if second element is same then sort it
    // according to the first element but in descending order

    pair<int, int> p[] = {{1, 2}, {2, 1}, {4, 1}};

    sort(p, p+3, comp);

    int n = sizeof(p) / sizeof(p[0]);
    for(int i=0; i<n; i++){
        cout<<"{"<<p[i].first<<" "<<p[i].second<<"} ";
    }
}

// count set bits (1s)
void setBits(){
    int a = 7;                                          // for 32 bit: 0000000.....0111
    cout << __builtin_popcount(a)<<endl;

    long long b = 39348982937;                          // for 64 bit: 
    cout<< __builtin_popcountll(b)<<endl;
}

// permutations
void permutation(){
    string a = "231";
    sort(a.begin(), a.end());

    do{
        cout<<a<<endl;
    }while(next_permutation(a.begin(), a.end()));              // it follows lexicographical order that's why to get all the permutations the number should be in sorted order

}

// max and min element
void maxAndMin(){
    vector<int> v;

    v.push_back(10);
    v.push_back(15);
    v.push_back(5);
    v.push_back(20);
    v.push_back(12);

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

    cout<<"max : "<<max<<endl;
    cout<<"min : "<<min<<endl;
}
int main(){
    maxAndMin();

    return 0;
}