#include <iostream>
#include <string>

// чтение выражения из консоли
void input(char &c, int &b) {

    std::cin >> c;
    if (c != '.') {
        std::cin >> b;
    }
}

// проверка числа из аргумента
int calc_args(const int &a, const int &b, const char &c) {
    int res = 0;
    if (c == '+') {
        res = a + b;
    } else if (c == '-') {
        res = a - b;
    }else if (c == '/') {
        res = a / b;
    } else if (c == '*') {
        res = a * b;
    } else if (c == '.') {
        res = a;
    }
    return res;
}

// вывод сообщение из аргумента в консоль
void print_res(const int &a, const int &b, const char &c, const int &res) {
    std::cout << a << c << b << "= ";
    std::cout << res << "\n";
}

int main() {
    int result;
    int b;
    char c;

    std::cin >> result;

    while (c != '.') {
        input(c,b);
        result = calc_args(result, b, c);
    }
    std::cout << "= " << result << "\n";

    return 0;
}