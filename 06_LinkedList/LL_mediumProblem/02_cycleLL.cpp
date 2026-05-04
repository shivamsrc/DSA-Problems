#include<bits/stdc++.h>
using namespace std;

// Detect a loop or cycle in the LinkedList (LC 141)

// DataType

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute
bool hasCycle(ListNode *head) {
    ListNode* temp = head;
    
    map<ListNode*, int> mp;

    while(temp){
        if(mp.find(temp) != mp.end()){
            return true;
        }
        else{
            mp.insert({temp, 1});
            temp = temp->next;
        }
    }

    return false;
}

// Optimal - using tortoise and hare algorith
// Here we'll be using a slow and a fast pointer
bool hasCycle2(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }

    return false;
}

int main(){

    return 0;
}