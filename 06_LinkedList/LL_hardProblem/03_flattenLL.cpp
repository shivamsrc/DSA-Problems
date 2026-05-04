#include<bits/stdc++.h>
using namespace std;

// Flatten the LL

class ListNode {
    public:
    int val;
    ListNode* child;
    ListNode* next;

    ListNode(int val1){
        val = val1;
        child = nullptr;
        next = nullptr;
    }

    ListNode(int val1, ListNode* child1){
        val = val1;
        child = child1;
        next = nullptr;
    }

    ListNode(int val1, ListNode* child1, ListNode* next1){
        val = val1;
        child = child1;
        next = next1;
    }
};


// Brute
ListNode* flattenLinkedList2(ListNode* &head) {
    ListNode* temp = head;
    vector<int> arr;

    while(temp){
        ListNode* t = temp;                   // to traverse vertically

        while(t){
            arr.push_back(t->val);
            t = t->child;
        }

        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    ListNode* newHead = new ListNode(arr[0]);
    ListNode* newTemp = newHead;
    for(int i=1; i<arr.size(); i++){
        ListNode* nextNode = new ListNode(arr[i]);
        newTemp->child = nextNode;
        newTemp = nextNode;
    }

    return newHead;
}

// Optimal
ListNode* mergeTwoLL(ListNode* l1, ListNode* l2){
    ListNode* dummyList = new ListNode(-1);
    ListNode* res = dummyList;

    while(l1 && l2){
        if(l1->val < l2->val){
            res->child = l1;
            res = l1;
            l1 = l1->child;
        }
        else{
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }

        res->next = NULL;
    }

    if(l1) res->child = l1;
    else res->child = l2;

    return dummyList->child;
}

ListNode* flattenLinkedList(ListNode* &head){
    if(!head || head->next == NULL) return head;

    ListNode* mergedHead = flattenLinkedList(head->next);                 // response from the next function in recursion will arrive here.

    return mergeTwoLL(head, mergedHead);
}

int main(){

    return 0;
}