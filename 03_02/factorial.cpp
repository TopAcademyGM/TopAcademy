#include <iostream>

int main() {
    int n, result;

    std::cout << "Input n = ";
    std::cin >> n;

    result = 1;
    // факториал  !n
    for (int i = 1; i <= n; i = i+1) {
        result = result * i;
    }

    std::cout << "!n = " << result << "\n";
    return 0;
}
