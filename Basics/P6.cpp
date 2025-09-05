#include<bits/stdc++.h>
using namespace std;

// pairs
void explainPairs(){
    pair<int, int> p = {1, 3};
    cout<<p.first<<" "<<p.second<<endl;

    //nested pairs
    pair<int, pair<char, int>> var = {1, {'c', 2}};
    cout<<var.first<<" "<<var.second.first<<" "<<var.second.second<<endl;

    //pairs with array
    pair<int, int> arr[] = {{1,2}, {10,4}, {20, 100}, {30,300}};
    cout<<arr[2].second;
}

// vectors
void explainVectors(){
    vector<int> v;

    // adding elements
    v.push_back(10);                  // creates object outside then copies it in the vector
    v.emplace_back(20);               // creates object directly in the vector's memory
    v.emplace_back(30);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});             // syntax difference between push_back and emplace_back for pair
    vec.emplace_back(1,2);

    vector<int> v2(5, 100);            // create a vector of size 5 (that can be changed) with all elements initialized to same value 100
    
    vector<int> v3(5);                  // all elemets initialized to 0

    vector<int> v4(v2);                  // copies v2 into v4
   
    
    // Accessing the vector
    cout<<v[0]<<" "<<v.at(1)<<" "<<v.back()<<endl;

    // Iterators - for accessing 

    vector<int>::iterator it = v.begin();             // points to the beginning element's address or memory of the vector
    it++;
    cout<<*(it)<<endl;

    vector<int>::reverse_iterator it2 = v.rbegin();    // points to the last element 
    cout<<*(it2)<<endl;

    vector<int>::iterator it3 = v.end();                // points to the memory location that comes just after the vector's end
    vector<int>::reverse_iterator it4 = v.rend();        // comes just before the beginning of the vector


    // loop
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }

    for(auto it = v.begin(); it != v.end(); it++){                        // auto, automatically recognizes the data type to vector<int>::iterator
        cout<<*(it)<<" ";
    }

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<"\n";

    // delete elements
    vector<int> vec2;
    vec2.emplace_back(5); vec2.emplace_back(10); vec2.emplace_back(15); vec2.emplace_back(20); vec2.emplace_back(25);

    vec2.erase(vec2.begin()+2);             // give the exact iterator address 

    vec2.erase(vec2.begin()+1, vec2.begin()+3);       // give the start and next to end element we wanna delete [)]

    for(auto it : vec2){
        cout<<it<<" ";
    }
    cout<<"\n";

    // insert function
    vector<int> vec3(2, 100);
    vec3.insert(vec3.begin(), 300);
    vec3.insert(vec3.begin()+1, 2, 200);

    vector<int> copy(2, 50);
    vec3.insert(vec3.end(), copy.begin(), copy.end());
    for(auto it = vec3.begin(); it != vec3.end(); it++){
        cout<<*(it)<<" ";
    }
    cout<<"\n";

    // length
    cout<<vec3.size()<<endl;

    // remove
    vec3.pop_back();
    for(auto it : vec3){
        cout<<it<<" ";
    }
    cout<<"\n";

    // swap two vectors
    vec2.swap(vec3);
    for(auto it : vec3){
        cout<<it<<" ";
    }
    cout<<"\n";

    // clear the vector
    vec3.clear();

    // check empty or not - boolean(0,1)
    cout<<vec3.empty();

}

int main(){
    explainVectors();

    return 0;
}
