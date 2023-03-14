#include <iostream>
#include <fstream>


void std_input_file(std::ifstream &fin) {
    std::string str_test;
    std::string str_test2;
    int int_test = 55;

    fin >> str_test;
    fin >> int_test;
    fin >> str_test2;

    std::cout << str_test << " "
              << int_test << " "
              << str_test2 << " "
              << fin.bad() << "\n";
}

// Выводит весь файл по названию в консоль
void print_all_file(const std::string &file_name) {
    // i - input (чтение)
    // f - file
    // stream - поток
    // char temp;
    std::string temp;
    std::ifstream file_in;
    file_in.open(file_name);

    // std::getline()

    while (file_in.good()) {
        // std::cin >> temp;
        // file_in >> temp;
        std::getline(file_in, temp);
        std::cout << temp << "\n";
    }
    file_in.close();
}

void std_line() {
    std::string str;
    std::getline(std::cin, str); // Читает до переноса строки (\n)
    // std::cin >> str;  // Читает до любого пустого символа (пробел, таб, перенос строки)
    std::cout << str;
}

int main(int argc, char const *argv[])
{
    // i - input (чтение)
    // f - file
    // stream - поток
    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name;
    std::cout << "File " << file_name << ":\n";

    print_all_file(file_name);
    // std_line();
    return 0;
}
