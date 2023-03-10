#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    int a = 5;
    // i - input (чтение)
    // f - file
    // stream - поток
    std::ifstream fin;
    std::string file_name;
    std::string str_test;
    std::string str_test2;
    int int_test = 55;

    std::cout << "Input file name: ";
    std::cin >> file_name;
    std::cout << "File " << file_name << ":\n";
    fin.open(file_name);

    fin >> str_test;
    fin >> int_test;
    fin >> str_test2;

    std::cout << str_test << " "
              << int_test << " "
              << str_test2 << " "
              << fin.bad() << "\n";

    return 0;
}
