#include <bits/stdc++.h>

using namespace std;

long long k, fact = 1;

int main()
{
    cin >> k;
    long long i;
    if (k % 2 == 0) i = 2;
    else i = 1;

    for (i; i <= k; i += 2)
    {
        fact *= i;
    }

    cout << fact;
}