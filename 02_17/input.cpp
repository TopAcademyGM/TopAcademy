#include <iostream>
#include <string>

int input_data(std::string &name, int &pass) {
    std::cout << "Введите Имя: ";
    std::cin >> name;
    std::cout << "Введите Пароль: ";
    std::cin >> pass;

    if (std::cin.bad()) {
        return -3;
    }

    return 1;
}