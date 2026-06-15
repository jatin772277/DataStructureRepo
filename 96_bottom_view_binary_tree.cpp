#include<iostream>
#include<vector>
#include<map>
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
Node* buildTree(vector<int> &arr){
    if(arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < arr.size()){
        Node* curr = q.front();
        q.pop();
        if(i < arr.size() && arr[i] != -1){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
vector<int> BottomView(Node* root){
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if(node->left) q.push({node->left,line - 1});
        if(node->right) q.push({node->right,line + 1});
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,-1,-1,8,-1,-1,9,-1,-1};
    Node* root = buildTree(arr);
    vector<int> ans = BottomView(root);
    cout<<"Bottom View: ";
    for(int x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
