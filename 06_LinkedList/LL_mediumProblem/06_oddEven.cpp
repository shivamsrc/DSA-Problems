#include<bits/stdc++.h>
using namespace std;

// group odd index node first then even index node (LC 328)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute -> just repkace the values rather than changing the links
ListNode* oddEvenList2(ListNode* head) {
    ListNode* temp = head;

    vector<int> arr;
    while(temp != NULL && temp->next != NULL){
        arr.emplace_back(temp->val);
        temp = temp->next->next;
    }
    if(temp) arr.emplace_back(temp->val);

    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        arr.emplace_back(temp->val);
        temp = temp->next->next;
    }
    if(temp) arr.emplace_back(temp->val);

    temp = head;
    for(int i=0; i<arr.size(); i++){
        temp->val = arr[i];
        temp = temp->next;
    }

    return head;
}

// Optimal ->
ListNode* oddEvenList(ListNode* head){
    if(!head || head->next == NULL) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main(){

    return 0;
}