#include <iostream>
using namespace std;

void bubbleSort(int arr[], int s)
{

    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // base case -- already sorted
    if (s == 0 | s == 1)
    {
        return;
    }

    // 1 case solve karle - baaki recursion karlega
    for (int i = 0; i < s-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // recursive call
    bubbleSort(arr, s - 1);
}

int main()
{
    int arr[6] = {23, 45, 27, 11, 5, 90};
    bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}