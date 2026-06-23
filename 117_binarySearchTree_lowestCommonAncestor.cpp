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
Node* LowestCommonAncestor(Node* root,Node* p,Node* q){
    if(!root) return NULL;
    int curr = root->data;
    if(curr > p->data && curr > q->data) return LowestCommonAncestor(root->left,p,q);
    if(curr < p->data && curr < q->data) return LowestCommonAncestor(root->right,p,q);
    return root;
}
int main(){
    vector<int> arr = {10,4,13,3,8,11,15,1,-1,6,9,-1,-1,-1,-1,-1,2,5,7};
    Node* root = buildTree(arr,0);
    Node* p = root->left->right->left;   // 6
    Node* q = root->left->right->right;  // 9
    Node* lca = LowestCommonAncestor(root,p,q);
    if(lca) cout<<"Lowest Common Ancestor: "<<lca->data<<endl;
    else cout<<"LCA Doesn't Exist!!"<<endl;
    return 0;
}