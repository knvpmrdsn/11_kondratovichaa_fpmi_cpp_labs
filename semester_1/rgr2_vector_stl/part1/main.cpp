#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

void InputVector(std::vector<int>& vec) 
{
    int x;
    std::cout << "Enter numbers (to end enter any letter):\n";
    while (std::cin >> x) {
        vec.push_back(x);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PrintVector(const std::vector<int>& vec) 
{
    for (int val : vec) std::cout << val << ' ';
    std::cout << '\n';
}

int SumVector(const std::vector<int>& vec) 
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int CountEqual(const std::vector<int>& vec, int target) 
{
    return std::count(vec.begin(), vec.end(), target);
}

int CountGreater(const std::vector<int>& vec, int n) 
{
    return std::count_if(vec.begin(), vec.end(), [n](int val){ return val > n; });
}

std::vector<int> ReplaceZeros(const std::vector<int>& vec) 
{
    std::vector<int> res = vec;
    if (res.empty()) return res;
    int mean = SumVector(res) / static_cast<int>(res.size());
    std::for_each(res.begin(), res.end(), [mean](int &val){ if (val == 0) val = mean; });
    return res;
}

std::vector<int> AddSum(const std::vector<int>& vec, int l, int r) 
{
    std::vector<int> res = vec;
    l--; r--;
    if (l < 0 || r >= static_cast<int>(res.size()) || l > r) return res;
    int interval_sum = std::accumulate(res.begin() + l, res.begin() + r + 1, 0);
    for (int &val : res) val += interval_sum;
    return res;
}

std::vector<int> ReplaceEven(const std::vector<int>& vec) 
{
    std::vector<int> res = vec;
    if (res.empty()) return res;
    int max_val = *std::max_element(res.begin(), res.end());
    int min_val = *std::min_element(res.begin(), res.end());
    int diff = max_val - min_val;
    for (int &val : res) if (abs(val) % 2 == 0) val = diff;
    return res;
}

std::vector<int> RemoveModEqual(const std::vector<int>& vec) 
{
    std::vector<int> res = vec;
    for (size_t i = 0; i < res.size(); ++i) {
        for (size_t j = i + 1; j < res.size(); ) {
            if (abs(res[i]) == abs(res[j])) res.erase(res.begin() + j);
            else ++j;
        }
    }
    return res;
}

int main() 
{
    std::vector<int> vec;
    InputVector(vec);

    std::cout << "Sum: " << SumVector(vec) << "\n";
    std::cout << "Count of numbers: " << vec.size() << "\n";

    int target;
    std::cout << "Enter a number to count: ";
    std::cin >> target;
    std::cout << "Count of " << target << "'s: " << CountEqual(vec, target) << "\n";

    int n;
    std::cout << "Enter n for > n condition: ";
    std::cin >> n;
    std::cout << "Count of numbers > " << n << ": " << CountGreater(vec, n) << "\n";

    std::vector<int> replaced_zeros = ReplaceZeros(vec);
    std::cout << "Vector after replacing zeros with mean: ";
    PrintVector(replaced_zeros);

    int l, r;
    std::cout << "Enter left and right borders of interval [l; r] (starting from 1, all included): ";
    std::cin >> l >> r;
    std::vector<int> added_sum = AddSum(vec, l, r);
    std::cout << "Vector after adding interval sum: ";
    PrintVector(added_sum);

    std::vector<int> replaced_even = ReplaceEven(vec);
    std::cout << "Vector after replacing even by abs numbers with max - min: ";
    PrintVector(replaced_even);

    std::vector<int> removed_mod = RemoveModEqual(vec);
    std::cout << "Vector after removing equal absolutes, except first: ";
    PrintVector(removed_mod);

    return 0;
}
