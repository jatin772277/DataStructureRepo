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
Node* DeleteHead(Node* head){
    if(head == nullptr) return nullptr;
    cout<<"Before Deleting Head: ";
    PrintList(head);
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* DeletePosition(Node* head,int pos){
    if(head == nullptr || pos <= 0) return head;
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    for(int i = 1;i < pos-1 && curr;i++) curr = curr->next;
    if(curr == nullptr || curr->next == nullptr) return head;
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
Node* DeleteValue(Node* head,int value){
    if(head == nullptr) return nullptr;
    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    while(curr->next && curr->next->data != value) curr = curr->next;
    if(curr->next == nullptr) return head;
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
Node* DeleteLast(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* curr = head;
    while(curr->next->next) curr = curr->next;
    Node* temp = curr->next;
    curr->next = nullptr;
    delete temp;
    return head;
}
int main(){
    vector<int> arr = {1,8,9,3,4,3,5,7,8,9};
    Node* head = makeList(arr);
    PrintList(head);
    head = DeleteHead(head);
    cout<<"After Deleting: ";
    PrintList(head);
    cout<<"Before Deletion Of Pos 3: ";
    PrintList(head);
    head = DeletePosition(head,3);
    cout<<"After Deletion of pos 3: ";
    PrintList(head);
    cout<<"Before deleting 7: ";
    PrintList(head);
    head = DeleteValue(head,7);
    cout<<"After deleting 7: ";
    PrintList(head);
    cout<<"Before deleting last: ";
    PrintList(head);
    head = DeleteLast(head);
    cout<<"After deleting last: ";
    PrintList(head);
    return 0;
}