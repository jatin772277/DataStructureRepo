#include<iostream>
#include<vector>
#include<unordered_set>
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
Node* FindStartPointLL1(Node* head){
    unordered_set<Node*> stt;
    Node* curr = head;
    while(curr){
        if(stt.count(curr)) return curr;
        stt.insert(curr);
        curr = curr->next;
    }
    return NULL;
}
Node* FindStartPointLL2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main(){
    vector<int> arr1 = {1,2,3,15,4,13,6,7,8,9};
    vector<int> arr2 = {1,2,3,4,5};
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    Node* curr = head1;
    while(curr->next) curr = curr->next;
    curr->next = head1->next->next->next;
    Node* ans1 = FindStartPointLL1(head1);
    Node* ans2 = FindStartPointLL1(head2);
    if(ans1) cout<<"Start Point: "<<ans1->data<<endl;
    else cout<<"No Starting point Linear Linked List!!!!"<<endl;
    if(ans2) cout<<"Start Point: "<<ans2->data<<endl;
    else cout<<"No Starting point Linear Linked List!!!!"<<endl;
    ans1 = FindStartPointLL2(head1);
    ans2 = FindStartPointLL2(head2);
    if(ans1) cout<<"Start Point: "<<ans1->data<<endl;
    else cout<<"No Starting point Linear Linked List!!!!"<<endl;
    if(ans2) cout<<"Start Point: "<<ans2->data<<endl;
    else cout<<"No Starting point Linear Linked List!!!!"<<endl;
    return 0;
}