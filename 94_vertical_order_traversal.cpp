#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
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
vector<vector<int>> VerticalOrderTraversal(Node* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first,y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left) todo.push({node->left,{x-1 , y + 1}});
        if(node->right) todo.push({node->right,{x + 1,y + 1}});
    }
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,4,10,9,10,-1,5,-1,-1,-1,-1,-1,6};
    Node* root = buildTree(arr);
    vector<vector<int>> answer = VerticalOrderTraversal(root);
    cout<<"Vertical Order Traversal: ";
    for(int i = 0;i < answer.size();i++){
        for(int j = 0;j < answer[i].size();j++) cout<<answer[i][j]<<" ";
    }
    cout<<endl;
    return 0;
}