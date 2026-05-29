#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
void Rearrange_array(vector<int> &arr){
    int positive = 0;
    int negative = 1;

    vector<int> temp(arr.size());
    vector<bool> filled(arr.size(), false);

    int negativeC = 0, positiveC = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < 0) negativeC++;
        else positiveC++;
    }

    int increment = 2;
    vector<int> remaining;

    for(int i = 0; i < arr.size(); i++){

        if(arr[i] >= 0){

            if(positive < arr.size()){
                temp[positive] = arr[i];
                filled[positive] = true;

                positive += increment;
                positiveC--;

                if(positiveC == 0)
                    increment = 1;
            }
            else{
                remaining.push_back(arr[i]);
            }

        }
        else{

            if(negative < arr.size()){
                temp[negative] = arr[i];
                filled[negative] = true;

                negative += increment;
                negativeC--;

                if(negativeC == 0)
                    increment = 1;
            }
            else{
                remaining.push_back(arr[i]);
            }

        }
    }

    int j = 0;

    for(int i = 0; i < temp.size(); i++){
        if(!filled[i]){
            temp[i] = remaining[j];
            j++;
        }
    }

    arr = temp;
}
int main(){
    vector<int> arr = {-1,-2,-3,1};
    cout<<"Array Before Rearrangement: ";
    printArray(arr);
    Rearrange_array(arr);
    cout<<"Array After Rearrangements: ";
    printArray(arr);
    return 0;
}