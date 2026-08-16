#include<iostream>
using namespace std;
bool isPalindrome(string str,int l,int r){
    if(str.size() == 1) return true;
    if(l >= r) return true;
    if(str[l] != str[r]) return false;
    else return isPalindrome(str,l + 1,r-1);
}
int main(){
    string str = "naman";
    string str2 = "namat";
    if(isPalindrome(str,0,str.size()-1)) cout<<str<<" is Palindrome!!!"<<endl;
    else cout<<"No Palindrome!!!"<<endl;
    if(isPalindrome(str2,0,str2.size()-1)) cout<<str2<<" is Palindrome!!!"<<endl;
    else cout<<"No Palindrome!!!"<<endl;
    return 0;
}