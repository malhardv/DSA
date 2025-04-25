#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &test, int pos, int &ans)
{
    if (pos == 0)
    {
        ans = test.top();
        return;
    }

    int temp = test.top();
    test.pop();

    solve(test, pos - 1, ans);
    test.push(temp);
}

void getMiddleElement(stack<int> test)
{
    int size = test.size();
    int pos = 0;
    int ans = 0;
    if (test.empty())
    {
        return;
    }
    else
    {

        if (size & 1)
        {
            pos = size / 2 + 1;
        }
        else
        {
            pos = size / 2;
        }
    }

    solve(test, pos - 1, ans);
    cout << "Middle element of stack: " << ans << endl;
}

void insertAtBottom(stack<int> &test, int element)
{
    int size = test.size();

    if (size == 0)
    {
        test.push(element);
        return;
    }

    int temp = test.top();
    test.pop();

    insertAtBottom(test, element);

    test.push(temp);
}

void reverseStack(stack<int> &test)
{
    if (test.empty())
    {
        return;
    }
    int temp = test.top();
    test.pop();

    reverseStack(test);

    insertAtBottom(test, temp);
}

void insertInSortedStack(stack<int> &test, int element)
{
    if (test.empty() || element > test.top())
    {
        test.push(element);
        return;
    }

    int temp = test.top();
    test.pop();

    insertInSortedStack(test, element);

    test.push(temp);
}

void sortStack(stack<int> &test)
{
    if (test.empty())
    {
        return;
    }
    int temp = test.top();
    test.pop();

    sortStack(test);
    insertInSortedStack(test, temp);
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> test;

    test.push(7);
    test.push(9);
    test.push(2);
    test.push(20);
    test.push(16);
    test.push(67);
    test.push(24);

    // getMiddleElement(test);
    // printStack(test);

    // insertAtBottom(test, 100);
    // printStack(test);

    // reverseStack(test);
    // printStack(test);

    printStack(test);

    sortStack(test);
    printStack(test);

    insertInSortedStack(test, 37);
    printStack(test);

    return 0;
}