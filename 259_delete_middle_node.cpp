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
void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* makeList(vector<int> &arr){
    if(!arr.size()) return NULL;
    Node* head = new Node(arr[0]);
    int n = arr.size();
    Node* curr = head;
    for(int i = 1;i < n;i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}
Node* DeleteMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}
int main(){
    vector<int> arr1 = {1,2,3,4,5,6};
    vector<int> arr2 = {1,2,3,4,5};
    cout<<"Before Deleting Middle: ";
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    cout<<endl<<"First: ";
    printList(head1);
    cout<<"Second: ";
    printList(head2);
    head1 = DeleteMiddle(head1);
    head2 = DeleteMiddle(head2);
    cout<<"After Deleting: "<<endl;
    cout<<"First: ";
    printList(head1);
    cout<<"Second: ";
    printList(head2);
    return 0;
}