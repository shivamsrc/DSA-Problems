#include<bits/stdc++.h>
using namespace std;

//  Delete the Middle Node of a Linked List (LC 2095) --> in odd the middle is clear but in case of even, there are two middles and the middle will be the later one.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//
ListNode* deleteMiddle(ListNode* head) {
    if(!head) return nullptr;

    if(head->next == NULL){
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* prev = nullptr;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = prev->next->next;
    return head;
    
}

int main(){

    return 0;
}