#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val,Node* next1,Node* prev1){
        this->data = val;
        this->next = next1;
        this->prev = prev1;
    }
    Node(int val){
        this->data = val;
        this->next = this->prev = nullptr;
    }
};
Node* makeList(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        Node* newNode = new Node(arr[i],nullptr,curr);
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}
void printList(Node* head){
    Node* curr = head;
    Node* temp = curr;
    cout<<"Print From Front: ";
    while(curr){
        cout<<curr->data<<" ";
        temp = curr;
        curr = curr->next;
    }
    cout<<endl;
    cout<<"Print From Back: ";
    curr = temp;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->prev;
    }
    cout<<endl;
}
vector<pair<int,int>> GiveAllPairsDLL(Node* head,int k){
    vector<pair<int,int>> res;
    if(!head) return res;
    Node* right = head;
    Node* left = head;
    while(right->next) right = right->next;
    while(left != right && right->next != left){
        int value = left->data + right->data;
        if(value == k){
            res.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        }
        else if(value > k) right = right->prev;
        else left = left->next;
    }
    return res;
}
int main(){
    vector<int> arr = {1,2,3,4,9};
    Node* head = makeList(arr);
    cout<<"List: ";
    printList(head);
    int sum = 5;
    vector<pair<int,int>> result = GiveAllPairsDLL(head,sum);
    cout<<"Result: ";
    for(auto it : result) cout<<"{"<<it.first<<" & "<<it.second<<"}"<<" ";
    cout<<endl;
    return 0;
}