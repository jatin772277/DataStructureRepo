#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
Node* buildTree(vector<int>& arr){
    if(arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < arr.size()){
        Node* curr = q.front();
        q.pop();
        // Left child
        if(i < arr.size() && arr[i] != -1){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // Right child
        if(i < arr.size() && arr[i] != -1){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
vector<int> TopView(Node* root){
    vector<int> answer;
    if(!root) return answer;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
        if(node->left) q.push({node->left,line - 1});
        if(node->right) q.push({node->right,line + 1});
    }
    for(auto it : mpp){
        answer.push_back(it.second);
    }
    return answer;
}

int main(){
    vector<int> arr = {1,2,3,4,5,-1,7,-1,-1,6,-1,-1,-1,-1,-1};
    Node* root = buildTree(arr);
    vector<int> answer = TopView(root);
    cout<<"Top View Of Binary Tree: ";
    for(int x : answer) cout<<x<<" ";
    cout<<endl;
    return 0;
}