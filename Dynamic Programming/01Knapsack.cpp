#include<iostream>
#include<vector>
using namespace std;

int solveUsingRec(int capacity, vector<int> weight, vector<int> profit, int index, int n) {
    // base case
    if(index >= n) {
        return 0;
    }

    // inclusion exclusion
    int include = 0;
    if(weight[index] <= capacity) {
        include = profit[index] + solveUsingRec(capacity - weight[index], weight, profit, index + 1, n);
    }
    int exclude = 0 + solveUsingRec(capacity, weight, profit, index + 1, n);

    return max(include, exclude);
}

void pringDPArray(vector<vector<int>> &dp) {
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

// SOLVE USING RECURSION + MEMOIZATION -----------------> TOP DOWN APPROACH
int solveUsingMemo(int capacity, vector<int> weight, vector<int> profit, int index, int n, vector<vector<int>> &dp) {
    // base case
    if(index >= n) {
        return 0;
    }

    if(dp[capacity][index] != -1) {
        return dp[capacity][index];
    }

    int include = 0;
    if(weight[index] <= capacity) {
        include = profit[index] + solveUsingMemo(capacity - weight[index], weight, profit, index + 1, n, dp);
    }
    int exclude = solveUsingMemo(capacity, weight, profit, index + 1, n, dp);

    dp[capacity][index] = max(include, exclude);
    printDPArray(dp);
    return dp[capacity][index];
}   

// SOLVE USING TABULATION ---------------------> BOTTOM UP APPROACH
int solveUsingTab(int capacity, vector<int> weight, vector<int> profit, int index, int n) {
    // base case
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    
    // analyse base case and fill the dp array

    // iterations
    
}

int main() {

    int capacity = 50;
    vector<int> weight = {10, 20, 30};
    vector<int> profit = {60, 100, 120};
    int index = 0;
    int n = 3;
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

    int ans = solveUsingMemo(capacity, weight, profit, index, n, dp);
    cout<<"Max Profit: "<<ans;

    return 0;
} 