#include <bits/stdc++.h>
using namespace std;

int prec(char a)
{
    if (a == '+' or a == '-')
        return 1;
    else if (a == '*' or a == '/')
        return 2;
    else
        return -1;
}

int main()
{
    string str;
    cin >> str;

    stack<char> s;

    for (auto i : str)
    {
        if ((i >= 'a' and i <= 'z') or (i >= '0' and i <= '9'))
            cout << i;
        else if (i == '(')
            s.push(i);
        else if (i == ')')
        {
            while (s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() and prec(i) <= prec(s.top()))
            {
                cout << s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}