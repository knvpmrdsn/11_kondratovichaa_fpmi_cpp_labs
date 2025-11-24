#include <iostream>
#include <fstream>

const int MAX_SIZE = 1e3;

void open_input(std::ifstream& fin)
{
    fin.open("input.txt");
    if (!fin.is_open())
    {
        throw "File can't be opened";
    }
    if (fin.eof())
    {
        throw "Empty file";
    }
}

void open_output(std::ofstream& fout)
{
    fout.open("output.txt");
    if (!fout.is_open())
    {
        throw "File can't be opened";
    }
}

void get_words(std::ifstream& fin, std::string& word1, std::string& word2)
{
    if (!(fin >> word1 >> word2))
    {
        throw "Not enough words";
    }
    fin.ignore();
}

int get_lines(std::ifstream& fin, std::string lines[])
{
    std::string line;
    int lines_counter = 0;
    while(getline(fin, line))
    {
        lines[lines_counter] = line;
        lines_counter++;
    }
    if (lines_counter == 0)
    {
        throw "No text";
    }
    if (lines_counter > MAX_SIZE)
    {
        throw "Too many lines";
    }

    return lines_counter;
}

bool is_delimiter(char c)
{
    return !((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool contains_word(const std::string line, const std::string word)
{
    std::string curr_word;
    for(size_t i = 0; i < line.size(); i++)
    {
        if (!is_delimiter(line[i]))
        {
            curr_word += line[i];
        }
        else
        {
            if (curr_word == word) return true;
            curr_word = "";
        }
    }
    return curr_word == word;
}

void swap_lines(std::string lines[], const std::string word1, const std::string word2, int lines_counter)
{
    int index1 = -1;
    int index2 = -1;
    for(int i = 0; i < lines_counter; i++)
    {
        if (index1 == -1 && contains_word(lines[i], word1)) index1 = i;
        if (index2 == -1 && contains_word(lines[i], word2)) index2 = i;
    }
    if (index1 != -1 && index2 != -1)
    {
        std::swap(lines[index1], lines[index2]);
    }
    else
    {
        throw "Not enough words to swap";
    }
}

void print_result(std::ofstream& fout, std::string lines[], int lines_counter)
{
    for(int i = 0; i < lines_counter; i++)
    {
        fout << lines[i] << '\n';
    }
}

int main()
{
    try {
        std::ifstream fin;
        std::ofstream fout;
        std::string word1, word2, lines[MAX_SIZE];
        int lines_counter;
        open_input(fin);
        open_output(fout);
        get_words(fin, word1, word2);
        lines_counter = get_lines(fin, lines);
        swap_lines(lines, word1, word2, lines_counter);
        print_result(fout, lines, lines_counter);
    }
    catch (const char* msg)
    {
        std::cout << msg;
    }
}