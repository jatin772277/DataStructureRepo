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
void PrintList(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* DeleteNthFromEnd(Node* head,int n){
    int length = 0;
    Node* curr = head;
    while(curr){
        length++;
        curr = curr->next;
    }
    Node* dummy = new Node(-1);
    dummy->next = head;
    curr = dummy;
    int len = length - n;
    for(int i = 0;i < len;i++){
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return dummy->next;
}
Node* DeleteNthFromEnd2(Node* head, int n) {
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* fast = dummy;
    for (int i = 0; i < n; i++) fast = fast->next;
    Node* slow = dummy;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int n = 3;
    Node* head = makeList(arr);
    cout<<"Before deleting: ";
    PrintList(head);
    cout<<"After Deleting: ";
    head = DeleteNthFromEnd(head,n);
    PrintList(head);
    cout<<"After Deleting One More: ";
    head = DeleteNthFromEnd2(head,n);//Slow fast pointer approach
    PrintList(head);
    return 0;
}