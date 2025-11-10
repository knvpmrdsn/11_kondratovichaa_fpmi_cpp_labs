#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    int fib0 = 0, fib1 = 1, fibn;
    for(int i = 0; i < n - 1; i++)
    {
        fibn = fib0 + fib1;
        fib0 = fib1;
        fib1 = fibn;
    }
    cout << fibn;
}