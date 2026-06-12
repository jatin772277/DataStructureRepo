#include<iostream>
#include<vector>
#include<queue>
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
void zigZagTraversal(Node* root){
    vector<vector<int>> result;
    if(!root) return;
    queue<Node*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;
    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);
        for(int i = 0;i < size;i++){
            Node* temp = nodesQueue.front();
            nodesQueue.pop();
            int index = (leftToRight) ? i : (size - i - 1);
            row[index] = temp->data;
            if(temp->left) nodesQueue.push(temp->left);
            if(temp->right) nodesQueue.push(temp->right);   
        }
        leftToRight = !(leftToRight);
        result.push_back(row);
    }
    for(int i = 0;i < result.size();i++){
        for(int j = 0;j < result[i].size();j++) cout<<result[i][j]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,56,6,7,7,8,88,9,99};
    Node* root = MakeCompleteBinaryTree(arr,0);
    zigZagTraversal(root);
    return 0;
}