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
Node* buildTree(vector<int>& arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left  = buildTree(arr,2*i+1);
    root->right = buildTree(arr,2*i+2);
    return root;
}
int MaxWidthBinaryTree(Node* root){
    if(!root) return 0;
    int ans = 0;
    queue<pair<Node* ,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first,last;
        for(int i = 0;i < size;i++){
            int cur_id = q.front().second - min;
            Node* node = q.front().first;
            q.pop();
            if(i == 0) first = cur_id;
            if(i == size - 1) last = cur_id;
            if(node->left) q.push({node->left,cur_id * 2 + 1});
            if(node->right) q.push({node->right,cur_id * 2 + 2});
        }
        ans = max(ans,last - first + 1);
    }
    return ans;
}
int main(){
    vector<int> arr = {1,3,2,5,-1,-1,4,7,-1,-1,-1,-1,-1,-1,6};
    Node* root = buildTree(arr,0);
    int maxwidth = MaxWidthBinaryTree(root);
    cout<<"Max Width Of Binary Tree: "<<maxwidth<<endl;
    return 0;
}