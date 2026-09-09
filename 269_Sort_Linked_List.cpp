#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
void PrintList(Node* head){
    Node* curr = head;
    cout<<"list: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* MakeList(vector<int>& arr){
    if(!arr.size()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}
Node* find_middle(Node* head){
    if(!head || !head->next) return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* Merge2SortedList(Node* head1,Node* head2){
    if(!head1 && !head2) return nullptr;
    if(head1 && !head2) return head1;
    if(!head1 && head2) return head2;
    Node* l1 = head1;
    Node* l2 = head2;
    Node* result = nullptr;
    Node* tail = nullptr;
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
Node* MergeSort(Node* head){
    if(!head || !head->next) return head;
    Node* middle = find_middle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = MergeSort(leftHead);
    rightHead = MergeSort(rightHead);
    head = Merge2SortedList(leftHead,rightHead);
    return head;
}
int main(){
    vector<int> arr = {3,1,4,2,5};
    Node* head = MakeList(arr);
    cout<<"Before Sorting: ";
    PrintList(head);
    cout<<"After Sorting: ";
    head = MergeSort(head);
    PrintList(head);
    return 0;
}