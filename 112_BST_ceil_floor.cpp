#include<iostream>
#include<vector>
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
    root->right = buildTree(arr,2*i + 2);
    return root;
}
int CeilBST(Node* root,int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key > root->data) root = root->right;
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
int FloorBST(Node* root,int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(key < root->data) root = root->left;
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
int main(){
    vector<int> arr = {10,5,13,3,6,11,14,2,4,-1,9};
    Node* root = buildTree(arr,0);
    int key1 = 8;
    int key2 = 12;
    int ans1 = CeilBST(root,key1);
    int ans2 = CeilBST(root,key2);
    int ans3 = FloorBST(root,key1);
    int ans4 = FloorBST(root,key2);
    cout<<"Ceil of the "<<key1<<" is: "<<ans1<<endl;
    cout<<"Ceil of the "<<key2<<" is: "<<ans2<<endl;
    cout<<"Floor of the "<<key1<<" is: "<<ans3<<endl;
    cout<<"Floor of the "<<key2<<" is: "<<ans4<<endl;
    return 0;
}