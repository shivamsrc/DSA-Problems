#include<bits/stdc++.h>
using namespace std;

// Intersection of two LinkedList (LC 160)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute (using hasing)
ListNode* getIntersectionNode2(ListNode *headA, ListNode *headB) {
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    map<ListNode*, int> mp;

    while(tempA){
        mp.insert({tempA, 1});
        tempA = tempA->next;
    }

    while(tempB){
        if(mp.find(tempB) != mp.end()){
            return tempB;
        }
        else{
            tempB = tempB->next;
        }
    }

    return NULL;
}

// Optimal (compare from the same level)
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    int sizeA = 0, sizeB = 0;

    while(tempA){
        sizeA++;
        tempA = tempA->next;
    }
    while(tempB){
        sizeB++;
        tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;

    int d = max(sizeA, sizeB) - min(sizeA, sizeB);
    if(sizeA > sizeB){
        for(int i=1; i<=d; i++){
            tempA = tempA->next;
        }
    }
    else if(sizeB > sizeA){
        for(int i=1; i<=d; i++){
            tempB = tempB->next;
        }
    }
    else{}

    while(tempA && tempB){
        if(tempA == tempB){
            return tempA;
        }
        else{
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }

    return NULL;
}

int main(){

    return 0;
}