#include<bits/stdc++.h>
using namespace std;

// Palindromic Linked List (LC 234)

//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute
bool isPalindrome(ListNode* head) {
    ListNode* temp = head;
    stack<ListNode*> st;

    while(temp){
        st.push(temp);
        temp = temp->next;
    }

    temp = head;

    while(temp){
        if(temp->val != st.top()->val){
            return false;
        }
        else{
            st.pop();
            temp = temp->next;
        }
    }

    return true;
}

// Optimal
ListNode* reverse(ListNode* head){
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

bool isPalindrome2(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverse(slow);
    ListNode* left = head;
    ListNode* right = newHead;
    while(right){
        if(left->val != right->val){
            return false;
        }
        else{
            left = left->next;
            right = right->next;
        }
    }

    reverse(slow);

    return true;
}

int main(){

    return 0;
}