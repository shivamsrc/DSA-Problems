#include<bits/stdc++.h>
using namespace std;

// STL

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
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); it++){                        // auto, automatically recognizes the data type to vector<int>::iterator
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<"\n";

    // delete elements
    vector<int> vec2;
    vec2.emplace_back(5); vec2.emplace_back(10); vec2.emplace_back(15); vec2.emplace_back(20); vec2.emplace_back(25);

    vec2.erase(vec2.begin()+2);             // give the exact iterator address 

    vec2.erase(vec2.begin()+1, vec2.begin()+3);       // give the start and next to end element we wanna delete [start, end)]

    for(auto it : vec2){
        cout<<it<<" ";
    }
    cout<<"\n";

    // insert function
    vector<int> vec3(2, 100);
    vec3.insert(vec3.begin(), 300);
    vec3.insert(vec3.begin()+1, 2, 200);

    vector<int> copy(2, 50);                                // just the vector's name is 'copy'
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

// list
void explainList(){
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);
    ls.pop_back();

    for(auto it : ls){
        cout<<it<<" ";
    }
    cout<<endl;

    // rest all functions are same as the vectors
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// deque
void explainDeque(){
    deque<int> dq;

    //
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);

    for(auto it : dq){
        cout<<it<<" ";
    }
    cout<<endl;

    //
    dq.pop_back();
    dq.pop_front();

    for(auto it : dq){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<dq.back()<<endl;
    cout<<dq.front()<<endl;

    // rest all functions are same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// stack
void explainStack(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout<<"top:"<<st.top()<<endl;

    // deletes the element at the top - LIFO
    st.pop();

    cout<<"top:"<<st.top()<<endl;

    cout<<"size:"<<st.size()<<endl;
    cout<<"empty?"<<st.empty()<<endl;

    stack<int> st1, st2;
    st1.swap(st2);
}

// queue
void explainQueue(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.emplace(5);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.back() += 6;
    cout<<q.back()<<endl;

    // delete elements that came first means from front
    q.pop();
    cout<<q.front()<<endl;

    // rest all functions are same as stack
    // empty, size, swap

}

// priority queue
void explainPQ(){
    // max-heap
    priority_queue<int> pq;

    pq.push(7);
    pq.push(4);
    pq.push(10); // top max
    pq.push(2);
    pq.emplace(5);

    cout<<pq.top()<<endl;
    
    pq.pop();
    
    cout<<pq.top()<<endl;

    // rest all other functions are same
    // size, empty, swap

    //min-heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(7);
    pq2.push(4);
    pq2.push(10);
    pq2.push(2); // top min
    pq2.push(5);

    cout<<pq2.top()<<endl;

}

// set - sorted, unique
void explainSet(){
    set<int> st;

    st.insert(10);
    st.emplace(7);
    st.insert(4);
    st.insert(9);
    st.insert(3);
    st.insert(12);

    set<int>::iterator it = st.find(7);              // gives the address of 7 and stores in iterator "it"
    auto it1 = st.find(20);                          // if element doesn't exists then gives the address of st.end()

    st.erase(4);

    int cnt = st.count(9);                           // give the no. of occurance of the provided element. if exists then 1(unique) if not then 0

    auto it2 = st.find(10);
    st.erase(it2);

    auto it3 = st.find(3);
    auto it4 = st.find(9);
    st.erase(it3, it4);                     // [start, end)

    // rest other functions are same as above
    // begin, end, rebegin, rend, empty, swap, size

    // upper & lower bound
    // set {9, 12}
    auto itU = st.upper_bound(9);
    auto itL = st.lower_bound(12);
    cout<<*(itU)<<endl;
    cout<<*(itL);
}

void explainMultiset(){
    multiset<int> ms;

    ms.insert(25);
    ms.insert(15);
    ms.insert(20);
    ms.insert(1);
    ms.emplace(1);
    ms.insert(1);
    ms.insert(1);
    ms.emplace(20);
    ms.emplace(20);
    // multiset {1, 1, 1, 1, 15, 20, 20, 20, 25}

    // deletes all the 20's
    ms.erase(20);

    auto it = ms.find(1);
    ms.erase(it);                                            // erases just the first occurance of the element

    ms.erase(ms.find(1), next(ms.find(1), 2));               // [start, end)

    cout<<*(ms.find(1));

}

void explainUnorderedSet(){
    unordered_set<int> st;
    // same as set except it is unordered
    // store elements in random fashoin
    // all function of set works except upper and lower bound
    // time complexity of all operations is mainly O(1), but rarely O(N)
}

// map - store value with unique key
void explainMap(){
    // initializing <key, value>
    map<int, int> mp;
    map<char, pair<int, int>> mp2;
    map<pair<int,int>, int> mp3;

    // storing in map
    mp[1] = 2;                                              // {1, 2}
    mp.emplace(2, 100);                                     // {{1, 2}, {2, 100}}
    mp.insert({3, 150});                                    // {{1, 2}, {2, 100}, {3, 150}}

    mp3[{1,7}] = 10;

    // loop

    for(auto it : mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"\n";

    // accessing
    cout<<mp[1]<<endl;
    cout<<mp[5]<<endl;

    auto it = mp.find(3);                           // if not found then points to .end()
    cout<<(*it).second;

    // all other functions works as above
    // upper_bound, lower_bound, size, swap, erase, empty

}

void explainMultimap(){
    // same as map but can use duplicate key
    // can't use mp[key]
}

void unorderedMap(){
    // same as map but stored in unsorted fashion
    //  time complexity of all operations is mainly O(1), but rarely O(N)
}


int main(){
    explainList();

    return 0;
}
