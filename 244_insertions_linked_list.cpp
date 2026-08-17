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
Node* InsertHead(Node* head,int value){
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
    return head;
}
Node* InsertLast(Node* head,int value){
    Node* temp = new Node(value);
    if(head == nullptr) return temp;
    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = temp;
    return head;
}
Node* InsertPosition(Node* head,int pos,int value){
    if(pos <= 0) return head;
    if(pos == 1){
        Node* temp = new Node(value);
        temp->next = head;
        return temp;
    }
    if(head == nullptr) return head;
    Node* curr = head;
    for(int i = 1;i < pos-1 && curr;i++) curr = curr->next;
    if(curr == nullptr) return head;
    Node* temp = new Node(value);
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
Node* InsertBeforeValue(Node* head,int value,int newValue){
    if(head == nullptr) return head;
    if(head->data == value){
        Node* temp = new Node(newValue);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* curr = head;
    while(curr->next && curr->next->data != value) curr = curr->next;
    if(curr->next == nullptr) return head;
    Node* temp = new Node(newValue);
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int main(){
    vector<int> arr = {1,8,9,3,4,3,5};
    Node* head = makeList(arr);
    PrintList(head);
    cout<<"Before Inserting at Head: ";
    PrintList(head);
    head = InsertHead(head,100);
    cout<<"After Inserting at Head: ";
    PrintList(head);
    cout<<"Before Inserting at Last: ";
    PrintList(head);
    head = InsertLast(head,200);
    cout<<"After Inserting at Last: ";
    PrintList(head);
    cout<<"Before Inserting at Position 3: ";
    PrintList(head);
    head = InsertPosition(head,3,300);
    cout<<"After Inserting at Position 3: ";
    PrintList(head);
    cout<<"Before Inserting Before 5: ";
    PrintList(head);
    head = InsertBeforeValue(head,5,400);
    cout<<"After Inserting Before 5: ";
    PrintList(head);
    return 0;
}