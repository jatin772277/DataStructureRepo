#include<bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> & vec){
    for(size_t i = 0;i < vec.size();i++){
        for(size_t j = 0;j < vec[0].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Printed!!!!!!!!!!!"<<endl;
}
int main(){
    // vector<vector<int>> vector1;//2d vector of 0*0
    // vector<vector<int>> vector1(3,vector<int>(4));//2d vector of 3*4
    // vector<vector<int>> vector2(3,vector<int>(4,3));
    // printMatrix(vector1);
    // printMatrix(vector2);
    // vector2.push_back({3,45,56,67});
    // printMatrix(vector2);
    vector<vector<int>> vector1;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vector<int> b;
    b.push_back(10);
    b.push_back(20);
    vector<int> c;
    c.push_back(19);
    c.push_back(24);
    c.push_back(27);
    vector1.push_back(a);
    vector1.push_back(b);
    vector1.push_back(c);

    for(auto vctr : vector1){
        for(auto it : vctr){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}