#include<bits/stdc++.h>
using namespace std;

// Sort List (LC 148) --> Given the head of a linked list, return the list after sorting it in ascending order.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute
ListNode* sortList2(ListNode* head) {
    ListNode* temp = head;
    vector<int> arr;

    while(temp){
        arr.emplace_back(temp->val);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());
    temp = head;
    int i =0;
    while(temp){
        temp->val = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

// Optimal using merge sort
ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummyNode->next;
}

ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* sortList(ListNode* head){
    if(!head || head->next == NULL) return head;

    ListNode* middle = findMid(head);
    ListNode* rightHead = middle->next;
    middle->next = nullptr;
    ListNode* leftHead = head;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return merge(leftHead, rightHead);
}

int main(){


    return 0;
}