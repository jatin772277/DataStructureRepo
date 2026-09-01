#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    Node(int val){
        data = val;
        next = nullptr;
        child = nullptr;
    }
    Node(int val,Node* nextN,Node* childN){
        data = val;
        next = nextN;
        child = childN;
    }
};
Node* MakeSinglyDown(vector<int>& arr){
    if(!arr.size()) return NULL;
    Node* head = new Node(arr[0]);
    int n = arr.size();
    Node* curr = head;
    for(int i = 1;i < n;i++){
        curr->child = new Node(arr[i]);
        curr = curr->child;
    }
    return head;
}
Node* MakeList(Node* head1,Node* head2,Node* head3,Node* head4,Node* head5){
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = nullptr;
    return head1;
}
void PrintList(Node* head){
    Node* curr = head;
    cout<<"List Downwise: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->child;
    }
    cout<<endl;
}
Node* merge(Node* head1,Node* head2){
    Node dummy(-1);
    Node* res = &dummy;
    while(head1 && head2){
        if(head1->data <= head2->data){
            res->child = head1;
            res = head1;
            head1 = head1->child;
        }
        else{
            res->child = head2;
            res = head2;
            head2 = head2->child;
        }
        res->next = nullptr;
    }
    if(head1) res->child = head1;
    else res->child = head2;
    if(res->child) res->child->next = nullptr;
    return dummy.child;
}
Node* FlattenLinkedList(Node* head){
    if(!head || !head->next) return head;
    Node* mergedHead = FlattenLinkedList(head->next);
    head = merge(head,mergedHead);
    return head;
}
int main(){
    vector<int> arr1 = {3};
    vector<int> arr2 = {2,10};
    vector<int> arr3 = {1,7,11,12};
    vector<int> arr4 = {4,9};
    vector<int> arr5 = {5,6,8};
    Node* head1 = MakeSinglyDown(arr1);
    Node* head2 = MakeSinglyDown(arr2);
    Node* head3 = MakeSinglyDown(arr3);
    Node* head4 = MakeSinglyDown(arr4);
    Node* head5 = MakeSinglyDown(arr5);
    Node* head = MakeList(head1,head2,head3,head4,head5);
    head = FlattenLinkedList(head);
    PrintList(head);
    return 0;
}