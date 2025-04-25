#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int s)
{
    // base case - arr is empty or has only one element
    if (s >= arr.size() - 1)
    {
        return;
    }

    // processing
    int min = s;
    for (int i = s + 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    swap(arr[s], arr[min]);
    selectionSort(arr, s + 1);
}

int main()
{
    vector<int> arr = {1, 23, 5, 12, 17};
    selectionSort(arr, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}