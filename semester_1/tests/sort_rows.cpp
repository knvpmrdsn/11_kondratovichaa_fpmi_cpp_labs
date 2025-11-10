#include <iostream>
#include <random>

const int MAX_SIZE = 15;

void choose_sort(char& sort_type)
{
    std::cout << "Choose sort type (b - bubble, i - insert, m - merge, c - count): ";
    std::cin >> sort_type;
}

void check_sort(char sort_type)
{
    while (sort_type != 'b' && sort_type != 'm' && sort_type != 'i' && sort_type != 'c')
    {
        choose_sort(sort_type);
    }
}

void choose_order(char& sort_order)
{
    std::cout << "Choose sort order (a - ascending, d - descending): ";
    std::cin >> sort_order;
}

void check_order(char sort_order)
{
    while (sort_order != 'a' && sort_order != 'd')
    {
        choose_order(sort_order);
    }
}

void input_size(int& rows, int& cols)
{
    std::cout << "Enter the number of rows (maximum - 15): ";
    std::cin >> rows;
    if (!std::cin)
    {
        exit(1);
    }

    std::cout << "Enter the number of columns (maximum - 15): ";
    std::cin >> cols;
    if (!std::cin)
    {
        exit(1);
    }
}

void check_size(int rows, int cols, const int MAX_SIZE)
{
    while (rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0)
    {
        input_size(rows, cols);
    }
}

int** allocate_matrix(int rows, int cols)
{
    int** mat = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        mat[i] = new int[cols];
    }

    return mat;
}

void choose_input(char& input_type)
{
    while (input_type != 'r' && input_type != 'k')
    {
        std::cout << "Choose type of matrix's input (r - random, k - keyboard): ";
        std::cin >> input_type;
    }
}

void random_fill(char input_type, int** mat, int rows, int cols)
{
    if (input_type != 'r') return;
    double l, r;
    std::cout << "Enter numbers' borders: ";
    std::cin >> l >> r;
    std::mt19937 gen(44035510);
    std::uniform_int_distribution<int> dist(l, r);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            mat[i][j] = dist(gen);
        }
    }
}

void keyboard_fill(char input_type, int** mat, int rows, int cols)
{
    if (input_type != 'k') return;
    std::cout << "Enter matrix's numbers:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            std::cin >> mat[i][j];
        }
    }
}

void output_matrix(int** mat, int rows, int cols, char if_needed)
{
    if (if_needed != 'r') return;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

bool comp(int a, int b, char sort_order)
{
    if (sort_order == 'a')
    {
        return a <= b;
    }
    else
    {
        return a >= b;
    }
}

void bubble_sort(int* mat, int cols, char sort_order)
{
    for(int i = 0; i < cols - 1; i++)
    {
        for(int j = 0; j < cols - i - 1; j++)
        {
            if (comp(mat[j + 1], mat[j], sort_order))
            {
                std::swap(mat[j], mat[j + 1]);
            }
        }
    }
}

void insert_sort(int* mat, int cols, char sort_order)
{
    for(int i = 1; i < cols; i++)
    {
        int key = mat[i];
        int j = i - 1;
        while(j >= 0 && comp(key, mat[j], sort_order))
        {
            mat[j + 1] = mat[j];
            j--;
        }
        mat[j + 1] = key;
    }
}

void merge(int *mat, int left, int mid, int right, int* temp, char sort_order)
{
    int i = left;
    int j = mid;
    int k = left;

    while(i < mid && j < right)
    {
        if(comp(mat[i], mat[j], sort_order))
        {
            temp[k] = mat[i];
            i++;
        }
        else
        {
            temp[k] = mat[j];
            j++;
        }
        k++;
    }
    while(i < mid)
    {
        temp[k] = mat[i];
        i++;
        k++;
    }
    while(j < right)
    {
        temp[k] = mat[j];
        j++;
        k++;
    }

    for(int t = left; t < right; t++)
        mat[t] = temp[t];

}

void merge_sort(int* mat, int left, int right, int* temp, char sort_order)
{
    if(right - left <= 1) return;

    int mid = (left + right) / 2;
    merge_sort(mat, left, mid, temp, sort_order);
    merge_sort(mat, mid, right, temp, sort_order);
    merge(mat, left, mid, right, temp, sort_order);
}

void count_sort(int* mat, int cols, char sort_order)
{
    int min_val = mat[0];
    int max_val = mat[0];
    for(int i = 1; i < cols; i++)
    {
        if(mat[i] < min_val) min_val = mat[i];
        if(mat[i] > max_val) max_val = mat[i];
    }

    int* cnt_array = new int[max_val - min_val + 1]();
    int* temp = new int[cols];
    int index = 0;

    for(int i = 0; i < cols; i++)
    {
        cnt_array[mat[i] - min_val]++;
    }

    if(sort_order == 'a')
    {
        for(int i = 0; i < (int)(max_val - min_val + 1); i++)
        {
            while(cnt_array[i] > 0)
            {
                temp[index++] = i + min_val;
                cnt_array[i]--;
            }
        }
    }
    else if(sort_order == 'd')
    {
        for(int i = max_val - min_val; i >= 0; i--)
        {
            while(cnt_array[i] > 0)
            {
                temp[index++] = i + min_val;
                cnt_array[i]--;
            }
        }
    }

    for(int i = 0; i < (int)cols; i++)
    {
        mat[i] = temp[i];
    }

    delete[] cnt_array;
    delete[] temp;
}


void sort_matrix(int** mat, int rows, int cols, char sort_type, char sort_order, int* temp)
{
    for(int i = 0; i < rows; i++)
    {
        if (sort_type == 'b')
        {
            bubble_sort(mat[i], cols, sort_order);
        }
        else if (sort_type == 'i')
        {
            insert_sort(mat[i], cols, sort_order);
        }
        else if (sort_type == 'm')
        {
            merge_sort(mat[i], 0, cols, temp, sort_order);
        }
        else if (sort_type == 'c')
        {
            count_sort(mat[i], cols, sort_order);
        }
    }
}

void delete_matrix(int** mat, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    char sort_type, input_type, sort_order;
    int rows, cols;
    int temp[MAX_SIZE];

    choose_sort(sort_type);
    check_sort(sort_type);
    choose_order(sort_order);
    check_order(sort_order);
    input_size(rows, cols);
    check_size(rows, cols, MAX_SIZE);

    int** mat = allocate_matrix(rows, cols);
    choose_input(input_type);
    random_fill(input_type, mat, rows, cols);
    keyboard_fill(input_type, mat, rows, cols);
    output_matrix(mat, rows, cols, input_type);

    sort_matrix(mat, rows, cols, sort_type, sort_order, temp);

    std::cout << "\nSorted matrix:\n";
    output_matrix(mat, rows, cols, 'r');

    delete_matrix(mat, rows);
    return 0;
}