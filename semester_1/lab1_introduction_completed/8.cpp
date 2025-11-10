#include <bits/stdc++.h>

using namespace std;

int ans;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (b < a && b < c) ans++;

    for(int i = 0; i < 7; i++)
    {
        a = b;
        b = c;
        cin >> c;
        if (b < a && b < c) ans++;
    }

    cout << ans;
}