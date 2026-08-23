#include<iostream>
#include<vector>
#include<unordered_map>
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
Node* MiddleElement(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    vector<int> arr1 = {3,1,4,6,2};
    vector<int> arr2 = {3,1,4,6,2,3};
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    Node* middle1 = MiddleElement(head1);
    Node* middle2 = MiddleElement(head2);
    cout<<"If length of Linked List is Even Then return second Middle!!"<<endl;
    if(middle1) cout<<"Middle of Linked list1: "<<middle1->data<<endl;
    if(middle2) cout<<"Middle of Linked list2: "<<middle2->data<<endl;
    return 0;
}