#include<bits/stdc++.h>
using namespace std;

// Remove Nth node from the end of the LL (LC 19)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return nullptr;
    ListNode* temp = head;
    int len = 0;

    while(temp){
        len++;
        temp = temp->next;
    }

    if(len == n){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    int cnt = 1;
    temp = head;

    while(temp){
        if(cnt == len - n){
            ListNode* target = temp->next;
            temp->next = target->next;
            delete target;
            return head;
        }
        else{
            cnt++;
            temp = temp->next;
        }
    }

    return head;
}

int main(){

    return 0;
}