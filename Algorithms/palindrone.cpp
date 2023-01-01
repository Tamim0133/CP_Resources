#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Is a Number palindrome 146 = 1 + 4 + 6 = 11 == 11 (Palindrome)
    string s;
    cin >> s;

    int digitSum = 0;

    for (auto i : s)
        digitSum += (i - '0');
    // Getting the character difference
    // If we do 'c' - 'a' then we will get 2 ; similarly for each character we can get their value by subtracting by 0

    string str = to_string(digitSum);
    string tmp = str;

    reverse(tmp.begin(), tmp.end());

    if (str == tmp)
        cout << "Yes ! Plindrome\n ";
    else
        cout << "Not Palindrome\n";

    return 0;
}