#include<iostream>
#include<vector>
using namespace std;
bool palindromeNumber(int n){
    vector<int> vect;
    while(n > 0){
        int a = n % 10;
        vect.push_back(a);
        n /= 10;
    }
    if(vect.size() == 1) return true;
    int left = 0;
    int right = vect.size() - 1;
    while(left <= right){
        if(vect[left] != vect[right]) return false;
        left++;
        right--;
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter The Number: "<<endl;
    cin>>n;
    if(palindromeNumber(n)) cout<<"Number is Palindrome!!"<<endl;
    else cout<<"Number is not palindrome!!!"<<endl;
    return 0;
}