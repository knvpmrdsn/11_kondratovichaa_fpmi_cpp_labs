#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    int day = 1, day_week = n, week = 1;
    cout << "1 |  ";
    for (int i = 1; i < day_week; i++)
    {
        cout << "   ";
    }

    while (day <= k)
    {
        cout << setw(2) << day;
        day++;
        day_week++;
        if (day_week == 8)
        {
            day_week = 1;
            week++;
            cout << endl;
            if (day <= k) {
                if (week >= 10) cout << week << "|  ";
                else cout << week << " |  ";
            }
        }
        else cout << ' ';
        
    }
}