#include <bits/stdc++.h>

using namespace std;

int n, s, p = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0) s += i;
        else p *= i;
    }
    cout << "sum = " << s << endl << "product = " << p;
}