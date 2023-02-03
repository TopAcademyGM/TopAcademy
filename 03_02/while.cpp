#include <iostream>

int main() {
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

    std::cout << "n^ch = " << result << "\n";
    return 0;
}
