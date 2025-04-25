#include <iostream>
using namespace std;

bool sortedCheck(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        // recursive call
        sortedCheck(arr + 1, size - 1);
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10};
    if (sortedCheck(arr, 10))
    {
        cout << "Sorted";
    }
    else
    {
        cout << "Not Sorted";
    }
}