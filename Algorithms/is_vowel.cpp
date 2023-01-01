#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{

    string s;
    cin >> s;

    int count = 0;

    for (auto i : s)
    {
        if (isVowel(i))
            count++;
    }
    return 0;
}