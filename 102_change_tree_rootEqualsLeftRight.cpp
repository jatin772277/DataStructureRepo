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
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2 * i + 2);
    return root;
}
void levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i < size;i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++) cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
void changeTree(Node* root){
    if(!root) return;
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    if(root->left || root->right) root->data = tot;
}
int main(){
    vector<int> arr = {2,35,10,2,3,5,2};
    Node* root = buildTree(arr,0);
    cout<<"Before Level Order traversal: ";
    levelOrder(root);
    changeTree(root);
    cout<<"After Level Order traversal: ";
    levelOrder(root);
    return 0;
}