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
int BurnTree(Node* root,Node* target){
    unordered_map<Node*,Node*> parent_track;
    MarkParent(root,parent_track);
    unordered_map<Node*,bool> Burned;
    queue<Node*> q;
    q.push(target);
    int time = 0;
    Burned[target] = true;
    while(!q.empty()){
        int size = q.size();
        bool flag = false;
        for(int i = 0;i < size;i++){
            Node* current = q.front();q.pop();
            if(current->left && !Burned[current->left]){
                Burned[current->left] = true;
                q.push(current->left);
                flag = true;
            }
            if(current->right && !Burned[current->right]){
                Burned[current->right] = true;
                q.push(current->right);
                flag = true;
            }
            if(parent_track[current] && !Burned[parent_track[current]]){
                Burned[parent_track[current]] = true;
                q.push(parent_track[current]);
                flag = true;
            }
        }
        if(flag) time++;
    }
    return time;
}
int main(){
    vector<int> arr = {3,5,1,6,2,0,8,-1,-1,7,4};
    Node* root = buildTree(arr,0);
    Node* target = root->left;
    int time = BurnTree(root,target);
    cout<<"Time Taken For Burning Tree: "<<time<<endl;
    return 0;
}