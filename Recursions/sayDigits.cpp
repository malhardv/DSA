#include <iostream>
using namespace std;

void sayDigits(int num)
{
    string numbers[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    // base case
    if (num == 0)
    {
        return;
    }

    // pre-processing
    int digit = num % 10;
    num = num / 10;

    // recursive call
    sayDigits(num);
    cout << numbers[digit] << " ";
}

int main()
{
    int num;
    cout << "Enter the number you want to say: ";
    cin >> num;
    sayDigits(num);
}