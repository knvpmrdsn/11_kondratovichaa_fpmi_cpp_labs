#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= min(n, m); i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            cout << i << ' '; 
        }
    }
}