#include <string>
#include <iostream>

void return_dynamic(int **var) {
    int *n = new int(15);
    long t = 7;

    *var = n; 
}
void return_static(int **var) {
    int n = 20;

    *var = &n; 
}
void print() {
    long n = 7;

    std::cout << "Hi! "<< n << "\n";
}


int main()
{
    int n = 15;
    std::string str;
    char arr[n];
    std::cout << "&n - " << &n << " " << sizeof(n);
    std::cout << "\n&str - " << &str << " " << sizeof(str);
    std::cout << "\n&arr - " << &arr << " " << sizeof(arr);

    int *d_n = new int();
    std::string *d_str = new std::string();
    std::cin >> n;
    char *d_arr = new char[n];
    std::cout << "\n&d_n - " << d_n << " " << sizeof(*d_n);
    std::cout << "\n&d_str - " << d_str << " " << sizeof(*d_str);
    std::cout << "\n&d_arr - " << (void *)d_arr << " " << sizeof(*d_arr);

    int *a;
    int *b;

    return_static(&a);
    print();
    return_dynamic(&b);
    print();

    std::cout << "\nA: " << *a << "\n";
    std::cout << "B: " << *b << "\n";

    return 0;
}
