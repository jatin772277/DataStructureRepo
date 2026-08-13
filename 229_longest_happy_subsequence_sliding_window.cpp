#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string str = "";
        int totalLength = a + b + c;
        int continuousA = 0,continuousB = 0,continuousC = 0;
        for(int i = 0;i < totalLength;i++){
            if((a >= b && a >= c && continuousA != 2) 
            || (continuousB == 2 && a > 0) || (continuousC == 2 && a > 0)){
                str += 'a';
                a--;
                continuousA++;
                continuousB = 0;
                continuousC = 0;
            }
            else if((b >= a && b >= c && continuousB != 2) 
            || (continuousA == 2 && b > 0) || (continuousC == 2 && b > 0)){
                str += 'b';
                b--;
                continuousB++;
                continuousA = 0;
                continuousC = 0;
            }
            else if((c >= a && c >= b && continuousC != 2) 
            || (continuousA == 2 && c > 0) || (continuousB == 2 && c > 0)){
                str += 'c';
                c--;
                continuousC++;
                continuousA = 0;
                continuousB = 0;
            }
        }
        return str;
    }
};
int main(){
    int a = 1,b = 1,c = 7;
    Solution obj;
    string str = obj.longestDiverseString(a,b,c);
    cout<<"Answer: "<<str<<endl;
    return 0;
}