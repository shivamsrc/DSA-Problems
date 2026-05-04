#include<bits/stdc++.h>
using namespace std;

// find starting of loop or cycle in the LinkedList (LC 142)

// DataType

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute
ListNode* detectCycle(ListNode *head) {
    ListNode* temp = head;
    
    map<ListNode*, int> mp;

    while(temp){
        if(mp.find(temp) != mp.end()){
            return temp;
        }
        else{
            mp.insert({temp, 1});
            temp = temp->next;
        }
    }

    return NULL;
}

ListNode* detectCycle2(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        };
    }

    return NULL;
}


int main(){

    return 0;
}