#include <bits/stdc++.h>

using namespace std;

int a, b, d;

int main() {
    cin >> a >> b >> d;
    while (a <= b)
    {
        if (a % 3 == 0) cout << a << ' ';
        a += d;
    }
    return 0;
}