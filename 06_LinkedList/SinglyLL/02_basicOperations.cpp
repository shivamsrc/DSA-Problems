#include<bits/stdc++.h>
using namespace std;

// DataType
class Node {
    public:

    int data;
    Node* next;

    // constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // we can have multiple constructors
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// Convert Array to LinkedList
Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);             // created a node at the heap and assigned it's memory pointer to the head. currently this node points to null.
    Node* mover = head;                        // we've also given the pointer to the first node to the mover so that the next pointer in the first node can be assigned when the second node is created.

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Length of LL
int lengthLL(Node* head){
    int cnt=0;
    Node* temp = head;

    while(temp){
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

// check if any given element is present or not
bool checkIfPresent(Node* head, int val){
    Node* temp = head;

    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }

    return 0;
}

int main(){
    vector<int> arr = {15,2,3,4,5};

    Node* ans = convertArr2LL(arr);

    cout<<ans->data<<"\n\n";


    // Traversal
    Node* temp = ans;

    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    cout<<"lenght: "<<lengthLL(ans)<<"\n\n";

    cout<<checkIfPresent(ans, 20);


    return 0;
}