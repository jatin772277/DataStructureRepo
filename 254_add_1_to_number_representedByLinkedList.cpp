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
Node* makeList(vector<int>& arr){
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
void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* ReverseList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node* AddOne1(Node* head){
    if(!head) return NULL;
    head = ReverseList(head);
    Node* curr = head;
    int carry = 1;
    Node* result = NULL;
    Node* tail = NULL;
    while(carry || curr){
        int value = carry;
        if(curr){
            value += curr->data;
            curr = curr->next;
        }
        carry = value / 10;
        value %= 10;
        if(!result){
            result = new Node(value);
            tail = result;
            continue;
        }
        else{
            tail->next = new Node(value);
            tail = tail->next;
        }
    }
    result = ReverseList(result);
    return result;
}
Node* AddOne2(Node* head){
    if(!head) return NULL;
    head = ReverseList(head);
    Node* curr = head;
    int carry = 1;
    while(curr || carry){
        int value = carry;
        if(curr) value += curr->data;
        carry = value / 10;
        value %= 10;
        curr->data = value;
        curr = curr->next;
    }
    return ReverseList(head);
}
int main(){
    vector<int> arr1 = {9,9,9,9};
    vector<int> arr2 = {1,2,3,5,6,7,8,9};
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    cout<<"Numbers Before Adding One: "<<endl;
    printList(head1);
    printList(head2);
    head1 = AddOne1(head1);
    head2 = AddOne1(head2);
    cout<<"Numbers After Adding One: "<<endl;
    printList(head1);
    printList(head2);
    cout<<endl<<"Again"<<endl<<endl;
    cout<<"Numbers Before Adding One: "<<endl;
    printList(head1);
    printList(head2);
    head1 = AddOne2(head1);
    head2 = AddOne2(head2);
    cout<<"Numbers After Adding One: "<<endl;
    printList(head1);
    printList(head2);
    return 0;
}