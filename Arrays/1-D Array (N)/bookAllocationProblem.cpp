#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
	int s = 0;
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += time[i];
	}
	int e = sum;
	int mid = s + (e - s) / 2;
	int sumPart = 0;

	vector<int> maxTime;
	for (int j = 1; j <= n; j++)
	{
		vector<int> allocate;
		sumPart = 0;
		for (int i = 0; i < m; i++)
		{
			while (sumPart + time[i] <= mid)
			{
				sumPart += time[i];
				break;
				allocate.push_back(sumPart);
			}
		}
		if (!allocate.empty())
		{
			int max = *max_element(allocate.begin(), allocate.end()); // Max partition time
			maxTime.push_back(max);									  // Store the max time for each student
		}
	}
	return *min_element(maxTime.begin(), maxTime.end());
}

int main()
{
	int n = 6;
	int m = 3;
	vector<int> arr = {30, 20, 10, 40, 5, 45};
	long long int min_time = ayushGivesNinjatest(n, m, arr);
	cout << min_time;
	return 0;
}
