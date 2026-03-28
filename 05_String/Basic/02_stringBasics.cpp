#include<bits/stdc++.h>
using namespace std;

// String
// A string is a sequence of characters. More technically, std::string is a class in the C++ Standard Library used to store and manipulate sequences of characters.
// Characters stored inside a string is contiguous in nature just like an array.


int main(){
    string a = "hiii";
    string b = "Itachi";

    // a string can be reinitialized as it's dynamic in nature.
    a = "hello";

    // strings can be concatenated as well
    string c = a + b;
    cout<<c<<endl;

    // strings can be compared as well
    cout<<(a == b)<<endl;
    cout<<(a > b)<<endl;                                                   // dictionary like comparison

    // we can check the lenght of a string as well
    cout<<b.length()<<endl;


    // input - getline(cin, str, delim?);
    string name;
    getline(cin, name);
    cout<<name<<endl;

    // we can also access specific characters based on index like arrays
    cout<<a[0];


    return 0;
}