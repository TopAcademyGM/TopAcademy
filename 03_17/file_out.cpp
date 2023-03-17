#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream fout;
    fout.open("hi");

    //std::cout << "Hello " << 42 << " " << 6.6; // запись в консоль
    fout << "Hello " << 42 << " " << 6.6;      // запись в файл hi

    return 0;
}
