#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* build(vector<int> &arr,int &i,int bound){
    if(i == arr.size() || arr[i] > bound) return NULL;
    Node* root = new Node(arr[i++]);
    root->left = build(arr,i,root->data);
    root->right = build(arr,i,bound);
    return root;
}
Node* BSTFromPreorder(vector<int> &arr){
    int i = 0;
    return build(arr,i,INT_MAX);
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<int> arr = {8,5,1,7,10,12};
    Node* root = BSTFromPreorder(arr);
    cout<<"preorder of input: ";
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    cout<<"preorder of Output: ";
    preorder(root);
    cout<<endl;
    return 0;
}