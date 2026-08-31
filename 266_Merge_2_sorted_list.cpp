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
Node* MakeList(vector<int>& arr){
    if(!arr.size()) return 0;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}
void PrintList(Node* head){
    Node* curr = head;
    cout<<"List: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* Merge2SortedList(Node* head1,Node* head2){
    if(!head1 && !head2) return NULL;
    if(!head1 && head2) return head2;
    if(head1 && !head2) return head1;
    Node* l1 = head1;
    Node* l2 = head2;
    Node* result = NULL;
    Node* tail = NULL;
    while(l1 && l2){
        int value;
        if(l1->data <= l2->data){
            value = l1->data;
            l1 = l1->next;
        }
        else{
            value = l2->data;
            l2 = l2->next;
        }
        if(!result){
            result = new Node(value);
            tail = result;
        }
        else{
            tail->next = new Node(value);
            tail = tail->next;
        }
    }
    if(l1) tail->next = l1;
    if(l2) tail->next = l2;
    return result;
}
int main(){
    vector<int> arr1 = {2,4,8,10};
    vector<int> arr2 = {1,3,3,6,11,14};
    Node* head1 = MakeList(arr1);
    Node* head2 = MakeList(arr2);
    Node* head3 = Merge2SortedList(head1,head2);
    cout<<"Before Merging: ";
    PrintList(head1);
    PrintList(head2);
    cout<<"After Merging: ";
    PrintList(head3);
    return 0;
}