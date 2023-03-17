#include <fstream>
#include <iostream>
#include <string>

std::string input_file_name() {
    std::string name;

    std::cout << "Введите имя файла: ";
    std::cin >> name;
    return name;
}

int main() {
    std::ifstream fin;
    std::string file_name = input_file_name();
    fin.open(file_name);

    if (fin.good()) {
        std::string full_file;
        while (fin.good()) {
            std::string tmp;
            std::getline(fin, tmp);
            full_file += tmp + "\n";
        }
        std::cout << full_file;
        std::ofstream fout;
        fout.open(file_name);
        int i = 0;
        while (full_file[i] != 0) {
            if (full_file[i] != ' ' && full_file[i] != '\t') {
                fout << full_file[i];
            }
            i++;
        }
    } else {
        std::cout << "file error!";
    }
}