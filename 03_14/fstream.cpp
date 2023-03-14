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

void copy_stream_to_stream(std::istream &in, std::ostream &out) {
    std::string temp;

    while (in.good()) {
        std::getline(in, temp);
        out << temp << "\n";
    }
}

void copy_file_to_file(const std::string &file_name_in,
                        const std::string &file_name_out) {
    // i - input (чтение)
    // o - output (запись, вывод)
    // f - file
    // stream - поток
    std::string temp;
    std::ifstream file_in;
    std::ofstream file_out;
    file_in.open(file_name_in);
    file_out.open(file_name_out);

    // std::getline()

    while (file_in.good()) {
        // std::cin >> temp;
        // file_in >> temp;
        std::getline(file_in, temp);
        // std::cout << temp << "\n";
        file_out << temp << "\n";
    }
    file_in.close();
    file_out.close();
}

// Выводит весь файл по названию в консоль
void print_all_file(const std::string &file_name) {
    // i - input (чтение)
    // f - file
    // stream - поток
    // char temp;
    // std::string temp;
    std::ifstream file_in;
    file_in.open(file_name);

    // std::getline()

    // while (file_in.good()) {
    //     // std::cin >> temp;
    //     // file_in >> temp;
    //     std::getline(file_in, temp);
    //     std::cout << temp << "\n";
    // }
    copy_stream_to_stream(file_in, std::cout);
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

    // std::cout << "Input file name: ";
    // std::cin >> file_name;
    // std::cout << "File " << file_name << ":\n";

    // print_all_file(file_name);

    std::string file_out;
    std::cout << "Input file name: ";
    std::cin >> file_name;
    std::cout << "Output file name: ";
    std::cin >> file_out;
    copy_file_to_file(file_name, file_out);
    // std_line();
    return 0;
}
