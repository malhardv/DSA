#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
	for(int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for(int k = j+1; k < n; k++) {
				if(arr[i] + arr[j] + arr[k] == K) {
                    if(i != j != k) {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[k]);
                        ans.push_back(temp);
                    }
                }
			}
		}
	}
	return ans;
}