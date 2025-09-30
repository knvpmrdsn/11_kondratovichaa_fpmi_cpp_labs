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
    double* array = new double [n];
    if (random_or_keyboard == 1)
    {
        cout << "Type array:\n";
        for(int i = 0; i < n; i++)
        {
            cin >> array[i];
            if (!cin)
            {
                cout << "Type error";
                delete[] array;
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
            delete[] array;
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



    double min = 1e9;
    int min_pos = 0;
    int first_pos = -1;
    int last_pos = n;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        if (array[i] <= min)
        {
            min = array[i];
            min_pos = i;
        }
        if (first_pos == -1 && array[i] > 0)
        {
            first_pos = i;
        }
        if (array[i] > 0)
        {
            last_pos = i;
        }
    }



    cout << "Min's position = " << min_pos + 1 << '\n';
    if (first_pos == -1 && last_pos == n)
    {
        cout << "No positive numbers\n";
    }
    else if (first_pos == last_pos)
    {
        cout << "One positive number\n";
    }
    else
    {
        for(int i = first_pos + 1; i < last_pos; i++)
        {
            sum += array[i];
        }
        cout << "Sum = " << sum << '\n';
    }



    double X;
    cout << "X = ";
    cin >> X;
    if (!cin)
    {
        cout << "Type error";
        delete[] array;
        exit(1);
    }
    int cnt = 0;
    for(int k = 0; k < n; k++)
    {
        int i;
        for(i = cnt; i < n; i++)
        {
            if (fabs(array[i]) > X)
            {
                cnt++;
                break;
            }
        }

        for(int j = i; j >= cnt; j--)
        {
            if (fabs(array[j]) > X && fabs(array[j - 1]) <= X) std::swap(array[j], array[j - 1]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << array[i] << ' ';
    }

    delete[] array;

    return 0;
}
