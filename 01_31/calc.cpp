#include <iostream>
#include <string>

// чтение выражения из консоли
void input(int &a, int &b, char &c) {

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "sign = ";
    std::cin >> c;
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
    }
    return res;
}

// вывод сообщение из аргумента в консоль
void print_res(const int &a, const int &b, const char &c, const int &res) {
    std::cout << a << c << b << "= ";
    std::cout << res << "\n";
}

int main() {
    int a;
    int b;
    char c;


    input(a,b,c);
    int res = calc_args(a, b, c);
    print_res(a, b, c, res);

    return 0;
}