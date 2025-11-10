#include <bits/stdc++.h>

using namespace std;

long long n, x, smallest, largest, s;

int main() {
    cin >> n;
    cin >> x;
    smallest = x;
    largest = x;
    s = x;
    for (long long i = 0; i < n - 1; i++)
    {
        cin >> x;
        s += x;
        smallest = min(smallest, x);
        largest = max(largest, x);
    }
    cout << s * 1.0 / n << ' ' << smallest << ' ' << largest;
    return 0;
}