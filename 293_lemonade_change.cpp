#include<iostream>
#include<vector>
using namespace std;
bool LemonadeChange(vector<int>& arr){
    int fives = 0;
    int tens = 0;
    for(int b : arr){
        if(b == 5) fives++;
        else if(b == 10){
            if(fives >= 1){
                fives--;
                tens++;
            }
            else return false;
        }
        else{
            if(fives >= 1 && tens >= 1){
                fives--;
                tens--;
            }
            else if(fives >= 3) fives -= 3;
            else return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr1 = {5,5,5,10,20};
    vector<int> arr2 = {5,5,10,10,20};
    int ans1 = LemonadeChange(arr1);
    int ans2 = LemonadeChange(arr2);
    if(ans1) cout<<"arr1 can return correct change!!!!!!!"<<endl;
    else cout<<"arr1 can't return correct change!!!!!!!"<<endl;
    if(ans2) cout<<"arr2 can return correct change!!!!!!!"<<endl;
    else cout<<"arr2 can't return correct change!!!!!!!"<<endl;
    return 0;
}