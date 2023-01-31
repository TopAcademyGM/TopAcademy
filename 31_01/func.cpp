#include <iostream>
#include <string>

int input_age();
std::string check_age(const int &age);
void print_mess(const std::string &mess);

// чтение одного числа из консоли
int input_age() {
    int age;

    std::cout << "Hello! Input your age: ";
    std::cin >> age;
    return age;
}

// проверка числа из аргумента
// возвращение строки в зависимости от результата
std::string check_age(const int &age) {
    std::string mess = "";
    if (age > 20) {
        mess = "Too old!";
    } else if (age > 14) {
        mess = "Hi teen!";
    }else {
        mess = "Too young!";
    }
    return mess;
}

// вывод сообщение из аргумента в консоль
void print_mess(const std::string &mess) {
    std::cout << mess << "\n";
}

int main() {
    int age = input_age();
    std::string mess = check_age(age);
    print_mess(mess);

    return 0;
}