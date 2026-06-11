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
Node* MakeCompleteBinaryTree(vector<int> &arr,int i){
    if(i >= arr.size()) return NULL;
    Node* root = new Node(arr[i]);
    root->left = MakeCompleteBinaryTree(arr,2*i + 1);
    root->right = MakeCompleteBinaryTree(arr,2*i + 2);
    return root;
}
int height(Node* root,int &diameter){
    if(!root) return 0;
    int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
    diameter = max(diameter , lh + rh);
    return  1 + max(lh,rh);
}
int diameterTree(Node* root){
    int diameter = 0;
    height(root,diameter);
    return diameter;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,56,6,7,7,8,88,9,99};
    Node* root = MakeCompleteBinaryTree(arr,0);
    int diameter = diameterTree(root);
    cout<<"max Length Path in tree(Diameter): "<<diameter<<endl;
    return 0;
}