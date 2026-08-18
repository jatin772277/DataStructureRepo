#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val,Node* next1,Node* prev1){
        this->data = val;
        this->next = next1;
        this->prev = prev1;
    }
    Node(int val){
        this->data = val;
        this->next = this->prev = nullptr;
    }
};
Node* makeList(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        Node* newNode = new Node(arr[i],nullptr,curr);
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}
void printList(Node* head){
    Node* curr = head;
    Node* temp = curr;
    cout<<"Print From Front: ";
    while(curr){
        cout<<curr->data<<" ";
        temp = curr;
        curr = curr->next;
    }
    cout<<endl;
    cout<<"Print From Back: ";
    curr = temp;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
    cout<<endl;
}
Node* DeleteHead(Node* head){
    if(!head) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    head->prev = nullptr;
    return head;
}
Node* DeletePosition(Node* head,int pos){
    if(!head || pos <= 0) return head;
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        if(head) head->prev = nullptr;
        return head;
    }
    Node* curr = head;
    for(int i = 1;i < pos && curr;i++) curr = curr->next;
    if(!curr) return head;
    Node* temp = curr;
    if(curr->prev) curr->prev->next = curr->next;
    if(curr->next) curr->next->prev = curr->prev;
    delete temp;
    return head;
}
Node* DeleteTail(Node* head){
    if(!head) return head;
    if(!head->next){
        delete head;
        return nullptr;
    }
    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->prev->next = nullptr;
    delete curr;
    return head;
}
Node* DeleteNode(Node* head, Node* node){
    if(!head || !node) return head;
    if(node == head){
        head = head->next;
        if(head) head->prev = nullptr;
        delete node;
        return head;
    }
    if(node->prev) node->prev->next = node->next;
    if(node->next) node->next->prev = node->prev;
    delete node;
    return head;
}
int main(){
    vector<int> arr = {2,3,4,5,6,8,6,3,4,7,8,2,3,4};
    Node* head = makeList(arr);
    cout<<"List: ";
    printList(head);
    head = DeleteHead(head);
    cout<<"After Deleting Head: ";
    printList(head);
    head = DeletePosition(head,3);
    cout<<"After Deleting position 3: ";
    printList(head);
    head = DeleteTail(head);
    cout<<"After Deleting tail: ";
    printList(head);
    head = DeleteNode(head,head->next->next->next);
    cout<<"After deleting Head->next->next->next: ";
    printList(head);
    return 0;
}