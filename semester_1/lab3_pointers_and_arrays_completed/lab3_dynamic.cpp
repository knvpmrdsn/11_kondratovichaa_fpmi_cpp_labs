#include <iostream>
#include <random>
#include <cmath>

const int MAX_SIZE = 3e5;

void check_input() {
    if (!std::cin)
        throw "Type error";
}

void choose_input_type(int& input_type) {
    std::cout << "Type 1 for keyboard and 0 for random: ";
    std::cin >> input_type;
    check_input();
    if (input_type != 0 && input_type != 1)
        throw "Invalid input type";
}

void input_size(int& n) {
    std::cout << "Type array's size: ";
    std::cin >> n;
    check_input();
    if (n > MAX_SIZE)
        throw "Overflow";
    if (n <= 0)
        throw "Array size must be positive";
}

void input_array(double* arr, int n) {
    std::cout << "Type array:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        check_input();
    }
}

void generate_array(double* arr, int n) {
    double l, r;
    std::cout << "Type array's numbers' borders: ";
    std::cin >> l >> r;
    check_input();
    if (l >= r)
        throw "Left border must be less than right border";

    std::mt19937 gen(44035510);
    std::uniform_real_distribution<double> dist(l, r);
    std::cout << "Random array:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void fill_array(double* arr, int n, int input_type) {
    if (input_type == 1)
        input_array(arr, n);
    else
        generate_array(arr, n);
}

void analyze_array(double* arr, int n, double& min_val, int& min_pos, int& first_pos, int& last_pos) {
    min_val = 1e9;
    min_pos = 0;
    first_pos = -1;
    last_pos = n;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= min_val) {
            min_val = arr[i];
            min_pos = i;
        }
        if (first_pos == -1 && arr[i] > 0)
            first_pos = i;
        if (arr[i] > 0)
            last_pos = i;
    }
    std::cout << "Min's position = " << min_pos + 1 << '\n';
}

void find_sum(double* arr, int n, int first_pos, int last_pos) {
    if (first_pos == -1 && last_pos == n) {
        std::cout << "No positive numbers\n";
        return;
    }
    if (first_pos == last_pos) {
        std::cout << "One positive number\n";
        return;
    }
    double sum = 0;
    for (int i = first_pos + 1; i < last_pos; i++)
        sum += arr[i];
    std::cout << "Sum = " << sum << '\n';
}

void input_x(double& x) {
    std::cout << "X = ";
    std::cin >> x;
    check_input();
}

void swap_array(double* arr, int n, double x) {
    int cnt = 0;
    for (int k = 0; k < n; k++) {
        int i;
        for (i = cnt; i < n; i++) {
            if (fabs(arr[i]) > x) {
                cnt++;
                break;
            }
        }

        for (int j = i; j >= cnt; j--) {
            if (fabs(arr[j]) > x && fabs(arr[j - 1]) <= x)
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

void print_array(double* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main() {
    double* arr = nullptr;

    try {
        int input_type, n;
        double min_val, x;
        int min_pos, first_pos, last_pos;

        choose_input_type(input_type);
        input_size(n);

        arr = new double[n];

        fill_array(arr, n, input_type);
        analyze_array(arr, n, min_val, min_pos, first_pos, last_pos);
        find_sum(arr, n, first_pos, last_pos);
        input_x(x);
        swap_array(arr, n, x);
        print_array(arr, n);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    delete[] arr;
    return 0;
}
