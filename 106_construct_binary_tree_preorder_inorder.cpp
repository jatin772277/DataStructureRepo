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
Node* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart
            ,int inEnd,unordered_map<int,int>& mapp)
{
    if(preStart > preEnd || inStart > inEnd) return NULL;
    Node* root = new Node(preorder[preStart]);
    int inRoot = mapp[root->data];
    int numsLeft = inRoot - inStart;
    root->left = build(preorder,preStart + 1,preStart + numsLeft,
                       inorder,inStart,inRoot - 1,mapp);
    root->right = build(preorder,preStart+ numsLeft + 1,preEnd,
                       inorder,inRoot + 1,inEnd,mapp);
    return root;
}
Node* buildTree(vector<int> &preorder,vector<int> &inorder){
    unordered_map<int,int> mapp;
    for(int i = 0;i < inorder.size();i++) mapp[inorder[i]] = i;
    return build(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1,mapp);
}
int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Node* root = buildTree(preorder,inorder);
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}