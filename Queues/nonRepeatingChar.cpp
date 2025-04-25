#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

string nonRepeatingChar(string s)
{
    if (s.size() == 0)
    {
        return "";
    }
}

int main()
{
    string s = "ababc";

    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        freq[c - 'a']++;
        q.push(c);

        // answer find karlo
        while (!q.empty())
        {
            char frontChar = q.front();
            if (freq[frontChar - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                cout << frontChar << " -> ";
                break;
            }
        }

        if (q.empty())
        {
            // no answer
            cout << "#" << " -> ";
        }
    }

    return 0;
}