#include <iostream>
#include <random>

const int size = 3e5;

int main() {
    using std::cin;
    using std::cout;
    int random_or_keyboard;
    cout << "Type 1 for keyboard and 0 for random: ";
    cin >> random_or_keyboard;
    if (!cin)
    {
        cout << "Type error";
        exit(1);
    }



    cout << "Type array's size: ";
    double array[size];
    int n;
    cin >> n;
    if (!cin)
    {
        cout << "Type error";
        exit(1);
    }
    if (n > size)
    {
        cout << "Overflow";
        return 0;
    }
    if (n == 0)
    {
        cout << "Empty array";
        return 0;
    }
    if (random_or_keyboard == 1)
    {
        cout << "Type array:\n";
        for(int i = 0; i < n; i++)
        {
            cin >> array[i];
            if (!cin)
            {
                cout << "Type error";
                exit(1);
            }
        }
    }
    else 
    {
        double l, r;
        cout << "Type array's numbers' borders: ";
        cin >> l >> r;
        if (!cin)
        {
            cout << "Type error";
            exit(1);
        }
        std::mt19937 gen(44035510);
        std::uniform_real_distribution<double> dist(l, r);
        for(int i = 0; i < n; i++)
        {
            array[i] = dist(gen);
            cout << array[i] << ' ';
        }
        cout << '\n';
    }



    double max = -2e9;
    int last_pos = n;
    for(int i = 0; i < n; i++)
    {
        if (array[i] > max) max = array[i];
        if (array[i] > 0) last_pos = i;
    }


    if (last_pos == n)
    {
        cout << "No positive numbers";
    }
    else
    {
        double sum = 0;
        for(int i = 0; i < last_pos; i++)
        {
            sum += array[i];
        }
        cout << "Sum = " << sum;
    }
    cout << "\nMax = " << max << '\n';
    



    double a, b;
    cout << "a, b = ";
    cin >> a >> b;
    if (!cin)
    {
        cout << "Type error";
        exit(1);
    }
    int cnt = 0;
    for(int k = 0; k < n; k++)
    {
        int i;
        for(i = 0; i < n - cnt; i++) 
        {
            if (fabs(array[i]) >= a && fabs(array[i]) <= b)
            {
                cnt++;
                break;
            }
        }

        for(int j = i; j < n - cnt; j++)
        {
            std::swap(array[j], array[j + 1]);
        }
        array[n - cnt] = 0;
    }
    


    for(int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }
    return 0;
}