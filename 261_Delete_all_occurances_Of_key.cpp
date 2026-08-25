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
Node* DeleteAllOccuranceKey(Node* head,int k){
    if(!head) return NULL;
    Node* temp = head;
    while(temp){
        if(temp->data == k){
            if(temp == head){
                head = temp->next;
                head->prev = nullptr;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;
            temp = nextNode;
        }
        else temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {10,4,10,10,6,10};
    Node* head = makeList(arr);
    cout<<"List: ";
    printList(head);
    head = DeleteAllOccuranceKey(head,10);
    cout<<"List: "<<endl;
    printList(head);
    return 0;
}