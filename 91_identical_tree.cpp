#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;Node* left;Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* MakeCompleteBinaryTree(vector<int> &arr,int i ){
    if(i >= arr.size()) return NULL;
    Node* root = new Node(arr[i]);
    root->left = MakeCompleteBinaryTree(arr,2 * i + 1);
    root->right = MakeCompleteBinaryTree(arr,2 * i + 2);
    return root;
}
bool isIdentical(Node* root1,Node* root2){
    if(!root1 || !root2) return (root1 == root2);
    return (root1->data == root2->data) && isIdentical(root1->left,root2->left) 
                                && isIdentical(root1->right,root2->right);
}
int main(){
    vector<int> arr1 = {1,3,2,4,5};
    vector<int> arr2 = {1,3,2,4,5};
    vector<int> arr3 = {1,2,3,4,5};
    Node* root1 = MakeCompleteBinaryTree(arr1,0);
    Node* root2 = MakeCompleteBinaryTree(arr2,0);
    Node* root3 = MakeCompleteBinaryTree(arr3,0);
    bool first = isIdentical(root1,root2);
    bool second = isIdentical(root1,root3);
    if(first) cout<<"First And Second Tree are Identical!!!"<<endl;
    else cout<<"First And Second Tree are not Identical!!!"<<endl;
    if(second) cout<<"Second And Third Tree are Identical!!!"<<endl;
    else cout<<"Second And Third Tree are not Identical!!!"<<endl;
    return 0;
}