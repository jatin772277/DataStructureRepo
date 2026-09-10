#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int val,Node* next = nullptr,Node* random = nullptr){
        this->data = val;
        this->next = next;
        this->random = random;
    }
};
void PrintList(Node* head){
    Node* curr = head;
    cout<<"List: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* MakeList(vector<int>& arr){
    if(!arr.size()) return nullptr;
    Node* head = new Node(arr[0]);
    int n = arr.size();
    Node* tail = head;
    for(int i = 1;i < n;i++){
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}
Node* CopyListRandomPointer1(Node* head){
    unordered_map<Node*,Node*> mpp;
    Node* curr = head;
    while(curr){
        Node* temp = new Node(curr->data);
        mpp[curr] = temp;
        curr = curr->next;
    }
    curr = head;
    Node* returnHead;
    for(auto it : mpp){
        Node* copyNode = it.second;
        Node* original = it.first;
        if(original == head) returnHead = copyNode;
        copyNode->next = original->next ? mpp[original->next] : nullptr;
        copyNode->random = original->random ? mpp[original->random] : nullptr;
    }
    return returnHead;
}
int main(){
    vector<int> arr = {7,13,10,11,1};
    Node* head = MakeList(arr);
    Node* curr = head;
    while(curr->next) curr = curr->next;
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = curr;
    curr = head->next->next;
    head->next->next->next->random = curr;
    head->next->next->next->next->random = head;

    Node* result = CopyListRandomPointer1(head);//Hashmap Implementation solution
    PrintList(result);
    return 0;
}