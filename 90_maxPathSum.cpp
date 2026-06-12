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
Node* MakeCompleteBinaryTree(vector<int> &arr,int i){
    if(i >= arr.size()) return NULL;
    Node* root = new Node(arr[i]);
    root->left = MakeCompleteBinaryTree(arr,2*i + 1);
    root->right = MakeCompleteBinaryTree(arr,2*i + 2);
    return root;
}
int maxPathDown(Node* root,int &maxi){
    if(!root) return 0;
    int left = max(0,maxPathDown(root->left,maxi));
    int right = max(0,maxPathDown(root->right,maxi));
    maxi = max(maxi , left + right + root->data);
    return max(left,right) + root->data;
}
int MaxPathSum(Node* root){
    int maxi = INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}
int main(){
    vector<int> arr = {-10,20,9,15,7};
    Node* root = MakeCompleteBinaryTree(arr,0);
    int maxPathSum = MaxPathSum(root);
    cout<<"Path Which have Max Sum having Sum equal to: "<<maxPathSum<<endl;
    return 0;
}