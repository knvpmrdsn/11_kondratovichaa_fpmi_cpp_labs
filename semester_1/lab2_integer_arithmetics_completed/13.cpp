#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    int a, b;
    cin >> a >> b;
    if (!cin)
    {
        exit(1);
    }
    
    for (int i = a; i <= b; i++)
    {
        int x = i;
        int k0 = 0;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        int k4 = 0;
        int k5 = 0;
        int k6 = 0;
        int k7 = 0;
        int k8 = 0;
        int k9 = 0;
        while (x != 0)
        {
            int last_digit = x % 10;
            if (last_digit == 0) k0++;
            if (last_digit == 1) k1++;
            if (last_digit == 2) k2++;
            if (last_digit == 3) k3++;
            if (last_digit == 4) k4++;
            if (last_digit == 5) k5++;
            if (last_digit == 6) k6++;
            if (last_digit == 7) k7++;
            if (last_digit == 8) k8++;
            if (last_digit == 9) k9++;
            x /= 10;   
        }
        if (k0 > 1 || k1 > 1 || k2 > 1 || k3 > 1 || k4 > 1
            || k5 > 1 || k6 > 1 || k7 > 1 || k8 > 1 || k9 > 1)
        {
            continue;
        }
        else cout << i << endl;
    }
    return 0;
}
