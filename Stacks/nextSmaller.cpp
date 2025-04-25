#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// next smaller elements
vector<int> nextSmallerElements(vector<int> &x)
{
    stack<int> check;
    check.push(-1);
    vector<int> answer;

    for (int i = x.size() - 1; i >= 0; i--)
    {
        int top = check.top();
        int curr = x[i];
        if (top < curr)
        {
            answer.insert(answer.begin(), top);
        }
        else
        {
            while (check.top() > curr)
            {
                check.pop();
            }
            answer.insert(answer.begin(), check.top());
        }
        check.push(curr);
    }
    return answer;
}

// previous smaller elements
vector<int> prevSmallerElements(vector<int> &x)
{
    stack<int> c;
    c.push(-1);
    vector<int> ans;

    for (int i = 0; i < x.size(); i++)
    {
        int curr = x[i];
        if (c.top() < curr)
        {
            ans.push_back(c.top());
        }
        else
        {
            while (curr < c.top())
            {
                c.pop();
            }
            ans.push_back(c.top());
        }
        c.push(curr);
    }

    return ans;
}

int main()
{
    vector<int> x;
    x.push_back(8);
    x.push_back(4);
    x.push_back(6);
    x.push_back(2);
    x.push_back(3);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Next Smaller Elements: ";
    vector<int> nextSmallerEle = nextSmallerElements(x);
    for (int i = 0; i < x.size(); i++)
    {
        cout << nextSmallerEle[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Previous Smaller Elements: ";
    vector<int> prevSmallerEle = prevSmallerElements(x);
    for (int i = 0; i < x.size(); i++)
    {
        cout << prevSmallerEle[i] << " ";
    }
    cout << endl;
}