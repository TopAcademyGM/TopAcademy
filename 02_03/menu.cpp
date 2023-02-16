#include <iostream>

void stepen() {
    int n, ch, result;

    std::cout << "Input n = ";
    std::cin >> n;
    std::cout << "Input ch = ";
    std::cin >> ch;

    result = n;
    // возведение в степень n^ch
    for (int i = 1; i != ch; i = i+1) {
        result = result * n;
    }
    std::cout << result << "\n";
}

int main() {
    while (1) {
        int menu;
        std::cout << "Hello\n";
        std::cout << "1.Степень\n"
                     "2.Факториал\n"
                     "3.Простые числа\n: ";
        std::cin >> menu;
        if (menu == 1) {
            stepen();
        } else {
            break;
        }
    }
    
    return 0;
}
