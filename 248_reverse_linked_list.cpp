#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val,Node* Next1){
        data = val;
        next = Next1;
    }
    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* makeList(vector<int>& arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        Node* curr = new Node(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    return head;
}
void PrintList(Node* head){
    Node* temp = head;
    cout<<"Printing List: ";
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* reverseLinkedList(Node* head){
    if(!head || !head->next) return head;
    Node* curr = head;
    Node* prev = nullptr;
    while(curr){
        Node* Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}
Node* reverseLinkedList2(Node* head){
    if(!head || !head->next) return head;
    Node* newHead = reverseLinkedList2(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = makeList(arr);
    PrintList(head);
    head = reverseLinkedList(head);
    cout<<"Reversed Linked List: ";
    PrintList(head);
    head = reverseLinkedList2(head);
    cout<<"Reversed Linked List: ";
    PrintList(head);
    return 0;
}