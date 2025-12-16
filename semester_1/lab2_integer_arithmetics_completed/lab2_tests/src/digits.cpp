#include <gtest/gtest.h>
#include <iostream>

bool all_digits_are_unique(int n)
{
    n = abs(n);
    int mask = 0;
    bool all_unique = true;

    while (n > 0)
    {
        int d = n % 10;
        int bit = 1 << d;

        if (mask & bit)
        {
            all_unique = false;
            break;
        }

        mask |= bit;
        n /= 10;
    }

    return all_unique;
}
