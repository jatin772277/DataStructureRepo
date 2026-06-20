#include<iostream>
#include<vector>
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
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2*i + 2);
    return root;
}
Node* SearchBST(Node* root,int target){
    while(root && root->data != target){
        if(root->data < target) root = root->right;
        else root = root->left;
    }
    return root;
}
int main(){
    vector<int> arr = {8,5,12,4,7,10,14,-1,-1,6,-1,-1,-1,13};
    Node* root = buildTree(arr,0);
    int target1 = 11;
    int target2 = 13;
    Node* node1 = SearchBST(root,target1);
    Node* node2 = SearchBST(root,target2);
    if(node1) cout<<"Node is in BST: "<<node1->data<<endl;
    else cout<<"Node is not in BST: NULL"<<endl;
    if(node2) cout<<"Node is in BST: "<<node2->data<<endl;
    else cout<<"Node is not in BST: NULL"<<endl;
    return 0;
}