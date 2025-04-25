#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr)
{
    int s = 0;
    int e = arr.size();
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(vector<int> &arr, int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivot = findPivot(nums);
    if (target > nums[0])
    {
        return binarySearch(nums, 0, pivot - 1, target);
    }
    else if (target < nums[0])
    {
        return binarySearch(nums, pivot, nums.size() - 1, target);
    }
    else
    {
        return pivot;
    }
}

int main()
{
    vector<int> arr = {1, 3};
    int ans = search(arr, 0);
    cout<<ans;
}