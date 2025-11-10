#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int n2 = n, n16 = n;
    string n_bin = "", n_hex = "";

    while (n2 != 0)
    {
        n_bin = char('0' + n2 % 2) + n_bin;
        n2 /= 2;
    }
    cout << n_bin << endl;

    while (n16 != 0)
    {
        if (n16 % 16 <= 9)
        {
            n_hex = char('0' + n16 % 16) + n_hex;
        }
        else
        {
            n_hex = char('A' + n16 % 16 - 10) + n_hex;
        }
        n16 /= 16;
    }
    cout << n_hex;
}