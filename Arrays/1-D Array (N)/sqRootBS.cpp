#include <iostream>
using namespace std;

int findRoot(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    float result;

    while (s <= e)
    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

double precisionRoot(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;
    for(int i = 0; i < precision; i++) {
        factor /= 10;
        for(double j = ans; j*j<n; j += factor) {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n = 0;
    int root = findRoot(n);
    cout << "Root is " << precisionRoot(n, 3, root)<<endl;
}