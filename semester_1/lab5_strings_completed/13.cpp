#include <iostream>
#include <string>

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_letter(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool is_alnum(char c) {
    return (is_digit(c) || is_letter(c));
}

void check_valid_char(char c) {
    if (!!(c >= 32 && c <= 126))
        throw "Invalid character in string";
}

bool only_digits(const std::string& word) {
    for (char c : word) {
        if (!is_digit(c)) return false;
    }
    return true;
}

bool only_letters(const std::string& word) {
    for (char c : word) {
        if (!is_letter(c)) return false;
    }
    return true;
}

bool letters_and_digits(const std::string& word) {
    bool has_digit = false;
    bool has_letter = false;
    for (char c : word) {
        if (is_digit(c)) has_digit = true;
        if (is_letter(c)) has_letter = true;
    }
    return has_digit && has_letter;
}

std::string process_word(std::string word) {
    if (only_digits(word) && word.size() < 7) {
        for (size_t i = 0; i < word.size() / 2; i++)
            std::swap(word[i], word[word.size() - i - 1]);
    } 
    else if (letters_and_digits(word)) {
        for (char &c : word)
            if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
    } 
    else if (only_letters(word)) {
        for (char &c : word)
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }
    return word;
}

std::string process_string(const std::string& str) {
    std::string result = "";
    std::string word = "";

    for (char c : str) {
        check_valid_char(c);

        if (is_alnum(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                result += process_word(word) + " ";
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        result += process_word(word);
    }

    return result;
}

void print_result(const std::string& result) {
    std::cout << result;
}

int main() {
    try {
        std::string input;
        std::getline(std::cin, input);

        std::string output = process_string(input);
        print_result(output);
    } 
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    return 0;
}
