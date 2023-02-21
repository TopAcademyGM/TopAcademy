#include <iostream>

void full_arr_input(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";
        // std::cin >> array[i];
        array[i] = rand() % 100; // 0 .. 99
    }
}

int main(int argc, char const *argv[]) 
{
    srand(time(NULL));
    const int cap = 100;
    int array[cap];
    int size;
    std::cout << "Введите размер: ";
    std::cin >> size;
    full_arr_input(array, size);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    return 0;
}


