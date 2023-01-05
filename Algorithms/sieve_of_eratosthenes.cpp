/*------------------------------
    Sieve of eratosthenes
------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> isPrime(n, true);
    vector<int> primes;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < isPrime.size(); i++)
    {
        if (isPrime[i] == true)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
