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
    Node(int val,Node* next1){
        data = val;
        next = next1;
    }
};
Node* MakeList(vector<int>& arr){
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
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* OddEvenLinkedList(Node* head){
    if(!head || !head->next) return head;
    Node* head2 = head->next;
    Node* odd = head;
    Node* even = head2;
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = head2;
    return head;
}
int main(){
    vector<int> arr = {2,3,1,4,5,6};
    Node* head = MakeList(arr);
    cout<<"Before Editing: ";
    printList(head);
    head = OddEvenLinkedList(head);
    cout<<"After Editing: ";
    printList(head);
    return 0;
}