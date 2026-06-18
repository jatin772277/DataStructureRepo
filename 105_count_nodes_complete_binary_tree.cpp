#include<iostream>
#include<vector>
#include<cmath>
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
Node* buildTree(vector<int>& arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2 * i + 1);
    root->right = buildTree(arr,2 * i + 2);
    return root;
}
int findHeightLeft(Node* root){
    int height = 0;
    while(root){
        height++;
        root = root->left;
    }
    return height;
}
int findHeightRight(Node* root){
    int height = 0;
    while(root){
        height++;
        root = root->right;
    }
    return height;
}
int CountNodesTree(Node* root){
    if(!root) return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if(lh == rh) return pow(2,lh) - 1;
    return 1 + CountNodesTree(root->left) + CountNodesTree(root->right);
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    Node* root = buildTree(arr,0);
    int totalNodes = CountNodesTree(root);
    cout<<"Total Nodes in Tree: "<<totalNodes<<endl;
    return 0;
}