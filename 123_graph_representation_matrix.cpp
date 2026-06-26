#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 4;

    // 0 means no edge
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    matrix[1][2] = 10;
    matrix[1][3] = 5;
    matrix[2][4] = 8;
    matrix[3][2] = 3;
    matrix[3][4] = 6;

    // Print Matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}