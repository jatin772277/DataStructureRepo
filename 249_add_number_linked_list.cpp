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
    Node* head = new Node(arr[0]);
    int n = arr.size();
    Node* curr = head;
    for(int i = 1;i < n;i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}
void printList(Node* head){
    cout<<"List Traversal: ";
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* reverseList(Node* head){
    if(!head || !head->next) return head;
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
Node* AddNumbers(Node* head1,Node* head2){
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    int carry = 0;
    Node* result = NULL;
    Node* tail = NULL;
    while(head1 || head2 || carry){
        int value = carry;
        if(head1){
            value += head1->data;
            head1 = head1->next;
        }
        if(head2){
            value += head2->data;
            head2 = head2->next;
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
    result = reverseList(result);
    return result;
}
int main(){
    vector<int> arr1 = {1,2,3,4,9};
    vector<int> arr2 = {1,2,7,8,9};
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    Node* result = AddNumbers(head1,head2);
    cout<<"Number in Result: ";
    printList(result);
    return 0;
}