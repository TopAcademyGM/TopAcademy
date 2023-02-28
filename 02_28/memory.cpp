#include <iostream>


void full_rand_arr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void new_size_arr(int **arr, int size, int new_size) {
    int *tmp = new int[new_size];
    int *buf;
    for (int i = 0; i < size && i < new_size; i++) {
        tmp[i] = (*arr)[i];
    }
    buf = *arr;
    *arr = tmp;

    delete [] buf;
}

void change(int *a) {
    *a = 10;
}

void new_int(int *a) {
    // int a = 10;
    a = new int(10);
}

int main() {
    int a = 5;

    change(&a);
    std::cout << a << "\n";

    std::string *d_str = new std::string("Name"); 

    int *b;
    new_int(b);
    //... работа с b
    delete b;
    delete d_str;

    // const int capasity = 10;
    // int static_arr[capasity];
    srand(time(NULL));
    int size;

    std::cin >> size;

    int *arr = new int[size];

    full_rand_arr(arr, size);
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    new_size_arr(&arr, size, size + 3);
    size = size + 3;
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete [] arr;

    return 0;
}