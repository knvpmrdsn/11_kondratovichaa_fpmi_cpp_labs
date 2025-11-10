#include <iostream>
#include <random>
#include <cmath>

const int MAX_SIZE = 200000;

void check_input() {
    if (!std::cin)
        throw "Type error";
}

void choose_input_type(int& input_type) {
    std::cout << "Type 1 for keyboard and 0 for random: ";
    std::cin >> input_type;
    check_input();
    if (input_type != 0 && input_type != 1)
        throw "Invalid character";
}

void input_array_size(int& n) {
    std::cout << "Type array's size: ";
    std::cin >> n;
    check_input();
    if (n <= 0)
        throw "Array's size must be positive";
    if (n > MAX_SIZE)
        throw "Overflow";
}

void fill_array_keyboard(double* arr, int n) {
    std::cout << "Type array:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        check_input();
    }
}

void fill_array_random(double* arr, int n, std::mt19937& gen) {
    double l, r;
    std::cout << "Type array's numbers' borders: ";
    std::cin >> l >> r;
    check_input();
    if (l > r)
        throw "Left border can't be greater than right border";

    std::uniform_real_distribution<double> dist(l, r);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void fill_array(double* arr, int n, int input_type, std::mt19937& gen) {
    if (input_type == 1)
        fill_array_keyboard(arr, n);
    else
        fill_array_random(arr, n, gen);
}

void find_max(double* arr, int n, double& max_val) {
    max_val = -2e9;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
}

void find_last_positive(double* arr, int n, int& last_pos) {
    last_pos = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) last_pos = i;
    }
}

void print_sum(double* arr, int last_pos, int n) {
    if (last_pos == n) {
        std::cout << "No positive numbers\n";
        return;
    }

    double sum = 0;
    for (int i = 0; i < last_pos; i++)
        sum += arr[i];
    std::cout << "Sum = " << sum << '\n';
}

void print_max(double max_val) {
    std::cout << "Max = " << max_val << '\n';
}

void input_a_b(double& a, double& b) {
    std::cout << "a, b = ";
    std::cin >> a >> b;
    check_input();
    if (a > b)
        throw "a can't be greater than b";
}

void swap_array(double* arr, int n, double a, double b) {
    int cnt = 0;
    for (int k = 0; k < n; k++) {
        int i;
        for (i = 0; i < n - cnt; i++) {
            if (fabs(arr[i]) >= a && fabs(arr[i]) <= b) {
                cnt++;
                break;
            }
        }

        for (int j = i; j < n - cnt; j++)
            std::swap(arr[j], arr[j + 1]);

        arr[n - cnt] = 0;
    }
}

void print_array(double* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main() {
    try {
        std::mt19937 gen(44035510);
        int input_type, n, last_pos;
        double max_val, a, b;
        double array[MAX_SIZE];

        choose_input_type(input_type);
        input_array_size(n);

        fill_array(array, n, input_type, gen);

        find_max(array, n, max_val);
        find_last_positive(array, n, last_pos);

        print_sum(array, last_pos, n);
        print_max(max_val);

        input_a_b(a, b);
        swap_array(array, n, a, b);

        print_array(array, n);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    return 0;
}
