// BINARY SEARCH USING RECURSIONS
#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key)
{

    // base case
    if (s > e)
    {
        return 0;
    }

    // processing and recursive call
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return 1;
    }
    else if (arr[mid] > key)
    {
        binarySearch(arr, s, mid - 1, key);
    }
    else
    {
        binarySearch(arr, mid + 1, e, key);
    }
}

int main()
{
    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int s = 0;
    int e = 10;
    int key = 1;
    if (binarySearch(arr, s, e, key))
    {
        cout << "The Element is Present!";
    }
    else
    {
        cout << "The element is Not Present.";
    }
    return 0;
}