#include<bits/stdc++.h>
using namespace std;

// Middle of the Linked List (LC 876) --> Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

// Given By Leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// just to create LL
ListNode* convertArr2LL(vector<int>& arr){
    ListNode* head = new ListNode(arr[0]);             // created a node at the heap and assigned it's memory pointer to the head. currently this node points to null.
    ListNode* mover = head;                        // we've also given the pointer to the first node to the mover so that the next pointer in the first node can be assigned when the second node is created.

    for(int i=1; i<arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}


// Normal approach (with 2 traversal)
ListNode* middleNode2(ListNode* head) {
    if(!head) return nullptr;

    ListNode* temp = head;
    int cnt = 0;

    while(temp){
        temp = temp->next;
        cnt++;
    }

    int mid = (cnt/2)+1;                              // middle element with 1 based indexing

    int cnt2 = 0;
    temp = head;
    while(temp){
        cnt2++;
        if(cnt2 == mid-1) return temp->next;                  // temp is still at the mid-1 element and returning it's next pointer which is pointing to the mid.
        temp = temp->next;
    }

    return head;
}


// Optimal (with 1 traversal)
// the fast one will move 2 steps and slow one will move 1 step. when the fast one will reach end the slow one will be at the middle. 
ListNode* middleNode(ListNode* head) {
    if(!head) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    ListNode* head = convertArr2LL(arr);

    ListNode* ans = middleNode(head);

    cout<<ans->val;

    return 0;
}