#include<iostream>
#include <vector>
using namespace std;
size_t find_max(vector<int> &vect){
    if(vect.size() == 0) return 0;
    int max = vect[0];
    for(size_t i = 1;i < vect.size();i++){
        if(max < vect[i]) max = vect[i];
    }
    return max;
}
int main(){
    int n;
    cout<<"Enter The n: ";
    cin >> n;
    vector<int> arr(n,0);
    for(size_t i =0 ;i< n;i++){
        cout<<"Enter The "<<i + 1<<"th Number: "<<endl;
        cin >> arr[i];
    }
    size_t max = find_max(arr);
    vector<int> hashArr(max + 1, 0);
    for(size_t i = 0;i < arr.size();i++){
        hashArr[arr[i]]++;
    }
    cout<<"Frequency of the Number in the array: "<<endl;
    for(size_t i = 0;i< hashArr.size();i++){
        cout<<"Frequency of the numbers: "<<i << " : "<<hashArr[i]<<endl;
    }
    return 0;
}