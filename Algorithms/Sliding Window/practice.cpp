// count anagrams
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string txt, pat;
    cin >> txt >> pat;

    int fr1[26] = {0};
    int fr2[26] = {0};

    for (auto i : pat)
        fr2[i - 'a']++;

    int i = 0, j = 0, count = 0, k = pat.size();

    while (j < txt.size())
    {
        fr1[txt[j] - 'a']++;
        if (j < k - 1)
            j++;
        else
        {
            bool anagram = true;
            for (int i = 0; i < 26; i++)
            {
                if (fr1[i] != fr2[i])
                {
                    anagram = false;
                    break;
                }
            }
            if (anagram)
                count++;

            fr1[txt[i] - 'a']--;

            i++;
            j++;
        }
    }
    cout << count << endl;

    return 0;
}