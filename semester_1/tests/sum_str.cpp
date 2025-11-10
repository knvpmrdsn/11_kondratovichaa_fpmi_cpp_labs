#include <iostream>
#include <string>
#include <algorithm>

bool is_valid_number(std::string& s) {
    if (s.empty()) throw "Input cannot be empty.";
    for (char c : s) {
        if (!isdigit(c))
            throw "Input must contain digits only.";
    }
    return true;
}

std::string read_input(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

std::string add_strings(std::string& a, std::string& b) {
    std::string A = a;
    std::string B = b;

    is_valid_number(A);
    is_valid_number(B);

    while (A.size() < B.size()) A = '0' + A;
    while (B.size() < A.size()) B = '0' + B;

    std::string result = "";
    int carry = 0;

    for (int i = A.size() - 1; i >= 0; --i) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry) result += '1';
    std::reverse(result.begin(), result.end());
    return result;
}

void write_output(const std::string& a)
{
    std::cout << "Result: " << a << '\n';
}

int main() {
    try {
        std::string a = read_input("Enter the first number: ");
        std::string b = read_input("Enter the second number: ");
        write_output(add_strings(a, b));
        
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}
