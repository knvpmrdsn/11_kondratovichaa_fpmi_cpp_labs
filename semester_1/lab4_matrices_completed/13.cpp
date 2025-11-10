#include <iostream>
#include <random>

const int SIZE = 700;

void choose_input_type(int& random_or_keyboard) {
    std::cout << "Type 1 for keyboard and 0 for random: ";
    std::cin >> random_or_keyboard;
    if (!std::cin)
        throw "Type error";
    if (random_or_keyboard != 0 && random_or_keyboard != 1)
        throw "Invalid character";
}

void input_matrix_size(int& n) {
    std::cout << "Type matrix's size: ";
    std::cin >> n;
    if (!std::cin)
        throw "Invalid size";
    if (n > SIZE)
        throw "Overflow";
    if (n <= 0)
        throw "Matrix's size must be positive";
}

void input_matrix_keyboard(int matrix[SIZE][SIZE], int n) {
    std::cout << "Type matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
            if (!std::cin)
                throw "Type error";
        }
}

void input_matrix_random(int matrix[SIZE][SIZE], int n, std::mt19937& gen) {
    int l, r;
    std::cout << "Type matrix's numbers' borders: ";
    std::cin >> l >> r;
    if (!std::cin)
        throw "Type error";
    if (l > r)
        throw "Left border can't be greater than right border";

    std::uniform_int_distribution<int> dist(l, r);
    std::cout << "Random matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            matrix[i][j] = dist(gen);
            std::cout << matrix[i][j] << ' ';
            if (j == n - 1) std::cout << '\n';
        }
}

int row_sum(int matrix[SIZE][SIZE], int n, int row) {
    int sum = 0;
    for (int j = 0; j < n; j++)
        sum += matrix[row][j];
    return sum;
}

void sort_matrix(int matrix[SIZE][SIZE], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (row_sum(matrix, n, j) > row_sum(matrix, n, j + 1)) {
                for (int k = 0; k < n; k++)
                    std::swap(matrix[j][k], matrix[j + 1][k]);
            }
        }
    }
    std::cout << "Sorted matrix:\n";
}

void print_matrix(int matrix[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}

void find_column(int matrix[SIZE][SIZE], int n) {
    bool found = false;
    for (int j = 0; j < n; j++) {
        found = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "First column without negative numbers is " << j + 1 << '\n';
            return;
        }
    }
    if (found)
        std::cout << "All columns have negative numbers\n";
}

void fill_matrix(int random_or_keyboard, int matrix[SIZE][SIZE], int n, std::mt19937& gen) {
    if (random_or_keyboard == 1)
        input_matrix_keyboard(matrix, n);
    else
        input_matrix_random(matrix, n, gen);
}

int main() {
    try {
        std::mt19937 gen(44035510);
        int random_or_keyboard, n;
        int matrix[SIZE][SIZE];

        choose_input_type(random_or_keyboard);
        input_matrix_size(n);
        fill_matrix(random_or_keyboard, matrix, n, gen);
        sort_matrix(matrix, n);
        print_matrix(matrix, n);
        find_column(matrix, n);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    return 0;
}
