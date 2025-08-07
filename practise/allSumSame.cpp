#include<iostream>
#include<vector>
using namespace std;

int balanceSums(vector<vector<int>> mat) {
    int maxSum = 0;
    int n = mat.size();

    // row sum
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        maxSum = max(sum, maxSum);
    }

    // col sum
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += mat[j][i];
        }
        maxSum = max(sum, maxSum);
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        res += maxSum - sum;
    }

    return res;
}

int main() {
    vector<vector<int>> mat =  
        {
          { 1, 2, 3 }, 
          { 4, 2, 3 }, 
          { 3, 2, 1 }
        };
                               
    cout << balanceSums(mat);
    return 0;
}
