#include<bits/stdc++.h>
using namespace std;

// namespace abc{
//     int val = 10;
// }
struct Node{
    string str;
    int abd;
    double d;
    char x;
    Node(string str__, int abd__, double d__, char x__){
        str = str__;
        abd = abd__;
        d = d__;
        x = x__;
    }
};
void printStruct(Node* a){
    cout<<a->abd<<" "<<a->d << " "<<a->str<<" "<<a->x<<endl;
}
int main(){
    int val = 50;
    cout<<val<<endl;
    // cout<<abc::val<<endl;
    Node* abc = new Node("abdevilliers",34,10.3,'R');
    // abc.abd = 34;
    // abc.d = 10.3;
    // abc.str = "abdevilliers";
    // abc.x = 'R';
    printStruct(abc);
    return 0;
}