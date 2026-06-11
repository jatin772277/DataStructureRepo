#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* MakeCompleteBinaryTree(vector<int> &arr,int i){
    if(i >= arr.size()) return NULL;
    Node* root = new Node(arr[i]);
    root->left = MakeCompleteBinaryTree(arr, 2*i + 1);
    root->right = MakeCompleteBinaryTree(arr, 2*i + 2);
    return root;
}
int maxDepth(Node* root){
    if(root == NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);
}
int main(){
    vector<int> arr = {1,23,4,5,6,7,8,9,4,13};
    Node* root = MakeCompleteBinaryTree(arr,0);
    int depth = maxDepth(root);
    cout<<"Max Depth of tree(depth of root is 1): "<<depth<<endl;
    return 0;
}