#include<bits/stdc++.h>
using namespace std;

// Reverse a LinkedList (LC 206)

class ListNode {
    public:

    int val;
    ListNode* next;

    ListNode(int val1){
        val = val1;
        next = nullptr;
    }

    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }
};

ListNode* vectorToLL(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i=1; i<arr.size(); i++){
        ListNode* newNode = new ListNode(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}


// Brute - using stack and only data reversal is happening here not the actual node reversal though we don't have to necessairly reverse the node
ListNode* reverseList1(ListNode* head) {
    ListNode* temp = head;

    stack<int> st;
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// Optiml - changing the links and reversing the node and return the new head
ListNode* reverseList(ListNode* head){
    if(!head) return nullptr;

    ListNode* curr = head;
    ListNode* prev = nullptr;

    while(curr){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Optimal (using Recursion)
ListNode* reverseList2(ListNode* head){
    // base condition
    if(!head || head->next == NULL) return head;

    ListNode* newHead = reverseList2(head->next);

    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

int main(){
    vector<int> arr = {1,2,3,4};

    ListNode* ans = vectorToLL(arr);

    ans = reverseList2(ans);


    // Traversal
    ListNode* temp = ans;

    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}