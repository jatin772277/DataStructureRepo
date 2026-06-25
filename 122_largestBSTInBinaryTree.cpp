#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
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
class NodeValue{
    public:
    int minNode,maxNode,maxSize;
    NodeValue(int minNode,int maxNode,int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
class Solution{
    public:
    NodeValue helper(Node* root){
        if(!root) return NodeValue(INT_MAX,INT_MIN,0);
        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);
        if(left.maxNode < root->data && root->data < right.minNode){
            return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode)
            ,left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    int largestBST(Node* root){
        return helper(root).maxSize;
    }
};
int main(){
    vector<int> arr = {20,15,40,14,18,30,60,-1,17,10,19,-1,-1,50};
    Node* root = buildTree(arr,0);
    Solution obj;
    int ans = obj.largestBST(root);
    cout<<"The Largest BST's size in Binary Tree is: "<<ans<<endl;
    return 0;
}