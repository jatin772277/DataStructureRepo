#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data,Node* next,Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    Node(int data){
        this->data = data;
        this->next = this->prev = nullptr;
    }
};
Node* makeList(vector<int>& arr){
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        Node* newNode = new Node(arr[i]);
        newNode->prev = curr;
        newNode->next = nullptr;
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}
void printList(Node* head){
    Node* curr = head;
    Node* prev = head;
    cout<<"Front Printing: ";
    while(curr){
        cout<<curr->data<<" ";
        prev = curr;
        curr = curr->next;
    }
    curr = prev;
    cout<<endl;
    cout<<"Back Printing: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
    cout<<endl;
}
void reverseDoublyLinkedListStack(Node* head){
    stack<int> st;
    Node* curr = head;
    while(curr){
        st.push(curr->data);
        curr = curr->next;
    }
    curr = head;
    while(curr){
        curr->data = st.top();
        st.pop();
        curr = curr->next;
    }
}
Node* reverseDLL(Node* head){
    if(!head || !head->next) return head;
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    } 
    return prev->prev;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    Node* head = makeList(arr);
    printList(head);
    cout<<"Reversing DLL With Stack: ";
    reverseDoublyLinkedListStack(head);
    printList(head);
    cout<<"Reversing DLL With One Go Approach: ";
    head = reverseDLL(head);
    printList(head);
    return 0;
}