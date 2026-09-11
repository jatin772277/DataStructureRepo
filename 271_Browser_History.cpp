#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Node{
    public:
    string data;
    Node* next;
    Node* back;
    Node() : data("0"),next(nullptr),back(nullptr){}
    Node(string x): data(x),next(nullptr),back(nullptr){};
    Node(string x,Node* y,Node* z): data(x),next(y),back(z){};
};
class BrowserHistory {
    Node* current;
    public:
    BrowserHistory(string homepage){
        current = new Node(homepage);
    }
    void visit(string url){
        Node* newN = new Node(url);
        current->next = newN;
        newN->back = current;
        current = newN;
    }
    string back(int steps){
        while(steps){
            if(current->back) current = current->back;
            else break;
            steps--;
        }
        return current->data;
    }
    string forward(int steps){
        while(steps){
            if(current->next) current = current->next;
            else break;
            steps--;
        }
        return current->data;
    }
};
int main(){
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com"); 
    string temp = browserHistory.back(1);
    cout<<"resultant string: "<<temp<<endl;
    temp = browserHistory.back(1);
    cout<<"resultant string: "<<temp<<endl;
    temp = browserHistory.forward(1);
    cout<<"resultant string: "<<temp<<endl;
    browserHistory.visit("linkedin.com");
    temp = browserHistory.forward(2);
    cout<<"resultant string: "<<temp<<endl;
    temp = browserHistory.back(2);
    cout<<"resultant string: "<<temp<<endl;
    temp = browserHistory.back(7);
    cout<<"resultant string: "<<temp<<endl;
    return 0;
}