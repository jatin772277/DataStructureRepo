#include<iostream>
#include<vector>
#include<unordered_map>
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
void inorderTraversal(Node* root){
    if(!root) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
Node* build(vector<int> &inorder,int inStart,int inEnd,
vector<int> &postorder,int postStart,int postEnd,unordered_map<int,int>& mapp){
    if(inStart > inEnd || postStart > postEnd) return NULL;
    Node* root = new Node(postorder[postEnd]);
    int inRoot = mapp[root->data];
    int numsLeft = inRoot - inStart;
    root->left = build(inorder,inStart,inRoot - 1,postorder,postStart,postStart + numsLeft - 1,mapp);
    root->right = build(inorder,inRoot + 1,inEnd,postorder,postStart + numsLeft ,postEnd - 1,mapp);
    return root;
}
Node* BuildTree(vector<int> &inorder,vector<int> &postorder){
    unordered_map<int,int> mapp;
    for(int i = 0;i < inorder.size();i++) mapp[inorder[i]] = i;
    return build(inorder,0,inorder.size() - 1,postorder,0,postorder.size() - 1,mapp);
}
int main(){
    vector<int> inorder = {8,4,9,2,10,5,1,6,3,7};
    vector<int> postorder = {8,9,4,10,5,2,6,7,3,1};
    Node* root = BuildTree(inorder,postorder);
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    return 0;
}