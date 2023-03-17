#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream fin;
    fin.open("hello");
    if (fin.good()) {
        // char temp = 0;
        // std::string temp;
        int temp;

        // std::cin >> temp; // чтение из консоли
        fin >> temp;         // чтение из файла "hello"

        std::cout << temp << "\n"; 
    } else {
        std::cout << "file error!\n";
    }

    return 0;
}
