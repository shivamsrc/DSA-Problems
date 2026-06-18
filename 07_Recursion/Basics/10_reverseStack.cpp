#include<bits/stdc++.h>
using namespace std;

// reverse a stack using recursion
void insertAtBottom(stack<int> &st, int temp){
    if(st.empty()){
        st.push(temp);
        return;
    }

    int ele = st.top();
    st.pop();
    insertAtBottom(st, temp);
    st.push(ele);
}

void reverseStack(stack<int> &st) {
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, temp);
}

int main(){
    stack<int> st;

    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    //{2,3,1,4}

    reverseStack(st);

    int n = st.size();
    for(int i=1; i<=n; i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    // expected output: {4,1,3,2}

    return 0;
}