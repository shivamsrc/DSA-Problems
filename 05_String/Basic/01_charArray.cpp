#include<bits/stdc++.h>
using namespace std;

// Character arrays

int main(){
    int arr[3] = {1,2,3};
    cout<<arr<<endl;                                  // it'll print the address of first element

    // character arrays
    char str[3] = {'a', 'b', 'c'};              // it's just an array of characters and not c-style string. when we print this, the cout will look for terminator '\0' but since it doesn't have it so it'll look for it until it finds the terminator and in that process it can print some garbage values as well along with the given characters.
    cout<<str<<endl;                            // char is a special case. it'll print the elements of the char array rather than the address


    char str2[4] = {'a', 'b', 'c', '\0'};          // this is a c-string with terminator.
    cout<<strlen(str2)<<endl;                     // its length will be calculated without terminator. so arraySize = 4, stringSize = 3


    char str3[] = "hello";                        // string literal - it's also a c-style string and the compiler actually stores it as --- | 'a' | 'b' | 'c' | '\0' | --- So a string literal is a null-terminated character array.
    // str3 = "world";                            // Arrays in C/C++ cannot be assigned after initialization. specific characters can be modified though.

    // INPUT AND OUTPUT

    char str4[10];

    cout<<"enter: "<<endl;
    cin>>str4;                                            // try "hello world"
    cout<<str4<<endl;


    cin.ignore();

    char str5[15];
    cout<<"enter: "<<endl;
    cin.getline(str5,15,'$');
    cout<<str5<<endl;


    // cin.getline(str,len, delim?) 
    // here delimitor is an option parameter which is used to specify the point till which the input will be read, usually it was enter but we can use diff. symbol here as well such as '$'


    return 0;
}