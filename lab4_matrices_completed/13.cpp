#include <iostream>
#include <random>

const int size = 10;

int sum(int n, int mat[size][size], int i)
{
    int sum = 0;
    for(int j = 0; j < n; j++)
    {
        sum += mat[i][j];
    }
    return sum;
}

int main()
{
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



    cout << "Type matrix's size: ";
    int matrix[size][size];
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
        cout << "Empty matrix";
        return 0;
    }
    if (random_or_keyboard == 1)
    {
        cout << "Type matrix:\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                {
                    cin >> matrix[i][j];
                    if (!cin)
                    {
                        cout << "Type error";
                        exit(1);
                    }
                }
        }
    }
    else 
    {
        int l, r;
        cout << "Type matrix's numbers' borders: ";
        cin >> l >> r;
        if (!cin)
        {
            cout << "Type error";
            exit(1);
        }
        std::mt19937 gen(44035510);
        std::uniform_int_distribution<int> dist(l, r);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = dist(gen);
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    bool swapped;
    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if (sum(n, matrix, j) > sum(n, matrix, j + 1))
            {
                std::swap(matrix[j], matrix[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
    cout << "\nSorted matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }



    bool found = false;
    for(int j = 0; j < n; j++)
    {
        found = false;
        for(int i = 0; i < n; i++)
        {
            if (matrix[i][j] < 0) 
            {
                found = true;
                break;
            }
        }
        if (!found) cout << "First column without negative numbers is " << j + 1 << '\n';
    }
    if (found) cout << "All columns have negative numbers\n";
}