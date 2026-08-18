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
Node* InsertionHead(Node* head,int val){
    if(!head){
        Node* newNode = new Node(val,nullptr,nullptr);
        return newNode;
    }
    Node* newNode = new Node(val);
    newNode->next = head;
    newNode->prev = nullptr;
    head->prev = newNode;
    head = newNode;
    return head;
}
Node* InsertionTail(Node* head,int val){
    if(!head){
        Node* newNode = new Node(val);
        return newNode;
    }
    Node* curr = head;
    while(curr->next) curr = curr->next;
    Node* newNode = new Node(val);
    newNode->prev = curr;
    curr->next = newNode;
    newNode->next = nullptr;
    return head;
}
Node* InsertionPosition(Node* head, int pos, int val){
    if(pos <= 0) return head;
    if(pos == 1){
        Node* newNode = new Node(val);
        if(!head) return newNode;
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    if(!head) return head;
    Node* curr = head;
    for(int i = 1; i < pos && curr; i++) curr = curr->next;
    if(!curr) return head;
    Node* newNode = new Node(val);
    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;
    return head;
}
Node* InsertionBeforeNode(Node* head, Node* curr, int val){
    if(!head || !curr) return head;
    Node* newNode = new Node(val);
    if(curr == head){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    newNode->prev = curr->prev;
    newNode->next = curr;
    curr->prev->next = newNode;
    curr->prev = newNode;
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    Node* head = makeList(arr);
    cout<<"List: ";
    printList(head);
    head = InsertionHead(head,100);
    cout<<"After Inserting 100 at Head: ";
    printList(head);
    cout<<"After Inserting 200 at Tail: ";
    head = InsertionTail(head,200);
    printList(head);
    cout<<"After Inserting at position 3: ";
    head = InsertionPosition(head,3,300);
    printList(head);
    cout<<"After Inserting 400 before head->next->next->next->next: ";
    head = InsertionBeforeNode(head,head->next->next->next->next,400);
    printList(head);
    return 0;
}