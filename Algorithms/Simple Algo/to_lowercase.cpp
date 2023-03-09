#include <bits/stdc++.h>
using namespace std;
string to_lower(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= 90 && s[i] >= 65)
            s[i] += 32;
    }
    cout << s << endl;
    return s;
}

int main()
{
    string s;
    cin >> s;

    string str = to_lower(s);

    return 0;
}