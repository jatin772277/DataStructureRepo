#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
void MarkParent(Node* root,unordered_map<Node*,Node*> &parent_track){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();q.pop();
        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}
vector<int> DistanceKNodes(Node* root,Node* target,int k){
    unordered_map<Node*,Node*> parent_track;
    MarkParent(root,parent_track);
    unordered_map<Node*,bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k ) break;
        for(int i = 0;i < size;i++){
            Node* current = q.front();q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
        while(!q.empty()){
            Node* curr = q.front();q.pop();
            result.push_back(curr->data);
        }
        return result;
}
int main(){
    vector<int> arr = {3,5,1,6,2,0,8,-1,-1,7,4};
    Node* root = buildTree(arr,0);
    Node* target = root->left;
    vector<int> ans = DistanceKNodes(root,target,2);
    cout<<"Nodes Which Are At Distance "<<2<<" From Node "<<target->data<<" is: ";
    for(int x : ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}