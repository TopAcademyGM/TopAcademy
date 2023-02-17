#include "database.hpp"

void put_error(int error) {
    if (error == -1) {
        std::cout << "Пользователь не найден";
    } else if (error == -2) {
        std::cout << "Не верный пароль";
    } else if (error == -3) {
        std::cout << "Системная ошибка";
    }
}

int find_user(std::string name, int pass) {
    
    for (int i = 0; i < count_user; ++i) {
        if (name == data_names[i]) {
            if (pass == data_pass[i]) {
                return 1;
            }
            return -2;
        }
    }
    
    return -1; // Пользователь не найден
}