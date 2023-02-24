#include <iostream>


void print_d(int n) {
    if (n != 0) {
        print_d(n / 2);
        std::cout << n % 2;
    }
}

void f() {
    int c;
}

int main() {

    int *ptr_a;

    int a = 8;
    int b = 0;
    ptr_a = new int(8);

    std::cout << &a << "\n";
    std::cout << &b << "\n";
    std::cout << ptr_a << "\n";
    
    // f();

    delete ptr_a;

    return 0;
}