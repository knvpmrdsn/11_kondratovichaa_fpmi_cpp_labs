#include <iostream>
#include <set>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "No primes" << std::endl;
        return 0;
    }

    std::set<int> numbers;
    for (int i = 2; i <= n; ++i) {
        numbers.insert(i);
    }

    for (int p = 2; p * p <= n; ++p) {
        if (numbers.find(p) != numbers.end()) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                numbers.erase(multiple);
            }
        }
    }

    std::cout << "All primes to " << n << ": ";
    for (int prime : numbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
