#include <iostream>

int main() {
    int n = 10;
    n = n + 5;
    n += 5; // n = n + (5);
    n++; // n += 1;
    n--; // n -= 1;
    ++n;
    --n;

    int a = 0;
    std::cout << ++a << "\n"; // 1
    std::cout << a << "\n"; // 1
    std::cout << a++ << "\n"; // 1
    std::cout << a << "\n"; // 2


    // for (int i = 0; i < 10; i++) {

    //     for (int j = 0; j < 10; j++) {
    //         std::cout << ".";
    //     }

    //     std::cout << "\n";
    // }
    std::cout << "1, 2, ";
    for (int i = 1; i <= 100; i++) {

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                break;
            }
            if (j == i - 1) {
                std::cout << i << ", ";
            }
        }
    }


    for (int i = 2; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            
        }
        
    }
    return 0;
}
