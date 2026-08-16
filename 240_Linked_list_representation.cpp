#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val, Node* next1){
        data = val;
        next = next1;
    }
    Node(int val){
        data = val;
        next = nullptr;
    }
    void addNodeBack(Node* node){
        Node* temp = this;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = node;
    }
    void addNodeFront(Node* node){
        Node* temp = new Node(data, next);
        data = node->data;
        next = temp;
    }
    void deleteNodeBack(){
        Node* temp = this;
        if(temp->next == nullptr) return;
        while(temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteNodeFront(){
        if(next == nullptr) return;
        Node* temp = next;
        data = temp->data;
        next = temp->next;
        delete temp;
    }
};
void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* makeList(vector<int> arr){
    Node* temp = new Node(arr[0],nullptr);
    Node* it = temp;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        Node* temp1 = new Node(arr[i]);
        it->addNodeBack(temp1);
        it = it->next;
    }
    return temp;
}
Node* makeList2(vector<int> arr){
    Node* head = new Node(arr[0],nullptr);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        Node* temp = new Node(arr[i],nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}
int lengthOfLinkedList(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}
int FindElement(Node* head,int target){
    Node* temp = head;
    int pos = 0;
    while(temp){
        if(temp->data == target) return pos + 1;
        pos++;
        temp = temp->next;
    }
    return -1;
}
void deleteNode(Node* head){
    Node* temp = head;
    while(temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}
void addNode(Node* head,int val){
    Node* node = new Node(val);
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = node;
}
int main(){
    vector<int> arr = {1,2,2,3,4,5};
    Node* head = makeList2(arr);
    printList(head);
    int len = lengthOfLinkedList(head);
    cout<<"Length: "<<len<<endl;
    int pos = FindElement(head,5);
    int pos1 = FindElement(head,6);
    cout<<"-1 element is not in linked list!!"<<endl;
    cout<<"Element "<<5<<" Found at Postion: "<<pos<<endl;
    cout<<"Element "<<6<<" Found at Postion: "<<pos1<<endl;
    cout<<"Before Deletion: ";
    printList(head);
    deleteNode(head);
    cout<<"After Deletion: ";
    printList(head);
    cout<<"Before Insertion: ";
    printList(head);
    addNode(head,5);
    cout<<"After Insertion: ";
    printList(head);
    return 0;
}