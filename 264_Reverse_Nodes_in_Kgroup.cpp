#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* MakeList(vector<int>& arr){
    if(!arr.size()) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}
void PrintList(Node* head){
    Node* curr = head;
    cout<<"List: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* ReverseList(Node* head){
    Node* curr = head;
    Node* prev = nullptr;
    while(curr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node* ReverseNodeKgroup(Node* head,int k){
    if(!head || k <= 1) return head;
    Node* curr = head;
    Node* prevGrptail = NULL;
    Node* newHead = NULL;
    while(curr){
        Node* temp = curr;
        for(int i = 0;i < (k-1) && temp;i++) temp = temp->next;
        if(!temp) break;
        Node* nextgrp = temp->next;
        temp->next = nullptr;
        Node* grouptail = curr;
        Node* reverseHead = ReverseList(curr);
        if(!newHead) newHead = reverseHead;
        if(prevGrptail) prevGrptail->next = reverseHead;
        prevGrptail = grouptail;
        curr = nextgrp;
        if(prevGrptail) prevGrptail->next = curr;
    }
    return newHead;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    Node* head = MakeList(arr);
    cout<<"Before Doing Operation: ";
    PrintList(head);
    cout<<"After Doing Operation: ";
    head = ReverseNodeKgroup(head,k);
    PrintList(head);
    return 0;
}