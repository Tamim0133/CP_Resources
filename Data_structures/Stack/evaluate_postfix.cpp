#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string str)
{
    stack<int> s;

    for (auto i : str)
    {
        if (isdigit(i))
            s.push(i - '0');
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (i)
            {
            case '+':
                s.push(val2 + val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string str;
    cin >> str;

    cout << evaluatePostfix(str);
    cout << endl;

    return 0;
}