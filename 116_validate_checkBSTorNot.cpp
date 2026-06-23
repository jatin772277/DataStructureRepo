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
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2*i + 2);
    return root;
}
bool isBST(Node* root, long long min, long long max) {
    if (!root) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}
bool isBSTTree(Node* root) {
    return isBST(root, LLONG_MIN, LLONG_MAX);
}
int main(){
    vector<int> arr = {13,10,15,7,12,14,17,-1,9,-1,-1,-1,-1,16,-1,-1,-1,8};
    Node* root = buildTree(arr,0);
    bool isBST = isBSTTree(root);
    if(isBST) cout<<"This Binary Tree is Binary Search Tree!!!"<<endl;
    else cout<<"This Binary Tree is Not Binary Search Tree!!!"<<endl;
    return 0;
}