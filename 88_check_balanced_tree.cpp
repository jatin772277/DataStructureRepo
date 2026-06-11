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
int dfsHeight(Node* root){
    if(root == NULL) return 0;
    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1) return -1; 
    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight ,rightHeight) + 1; 
}
bool checkBalanced(Node* root){
    return dfsHeight(root) != -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,56,6,7,7,8,88,9,99};
    Node* root = MakeCompleteBinaryTree(arr,0);
    bool isBalanced = checkBalanced(root);
    if(isBalanced) cout<<"Tree is Balanced!!"<<endl;
    else cout<<"Tree is Not Balanced!!"<<endl;
    return 0;
}