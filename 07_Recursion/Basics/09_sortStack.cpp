#include<bits/stdc++.h>
using namespace std;

// Sort a stack using recursion
void insertAtCorrectPos(stack<int> &st, int temp){
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }

    int ele = st.top();
    st.pop();
    insertAtCorrectPos(st, temp);
    st.push(ele);
}

void sortStack(stack<int> &st) {
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();
    sortStack(st);

    insertAtCorrectPos(st, temp);
}

int main(){
    stack<int> st;

    st.push(10);
    st.push(5);
    st.push(50);
    st.push(100);
    st.push(1);

    sortStack(st);

    int n = st.size();
    for(int i=1; i<=5; i++){
        cout<<st.top()<<" ";
        st.pop();
    }



    return 0;
}