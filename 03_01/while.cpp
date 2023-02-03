#include <iostream>

int main() {
    int n, ch, result;

    std::cout << "Input n = ";
    std::cin >> n;
    std::cout << "Input ch = ";
    std::cin >> ch;

    result = n;
    while (ch > 1) {
        result = result * n;
        ch = ch - 1;
    }

    std::cout << "n^ch = " << result << "\n";
    return 0;
}
