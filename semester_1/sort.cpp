#include <iostream>

const int SIZE_CONST = 5e5;

void input_size(int* size)
{
    std::cin >> *size;
}

void check_size(int size)
{
    if (size > SIZE_CONST)
    {
        std::cout << "Error";
    }
}

void input_arr(int (&arr)[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void bubble_sort(int (&arr)[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if (abs(arr[i]) < abs(arr[i - 1]))
        {
            for(int j = i; j > 0; j--)
            {
                if (abs(arr[j]) < abs(arr[j - 1])) 
                {
                    std::swap(arr[j], arr[j - 1]);
                }
            }
        }
    }
}

void output_arr(int (&arr)[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int main()
{
    int size;
    int arr[SIZE_CONST];
    input_size(&size);
    check_size(size);
    input_arr(arr, size);
    bubble_sort(arr, size);
    output_arr(arr, size);
}