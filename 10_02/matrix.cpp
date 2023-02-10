#include <iostream>

void full_rand(int *arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1; // 1 - 100
    }
}

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    srand(time(NULL));
    // const int capasity = 3;
    // int arr[capasity];
    // full_rand(arr, capasity);
    // print_arr(arr, capasity);

    const int x = 5, y = 5;
    int matrix[y][x];

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            matrix[i][j] = rand() % 100 + 1; // 1 - 100
        }
    }

    for (int i = 0; i < y; ++i) {

        for (int j = 0; j < x; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";

    }
    std::cout << "\n";




    return 0;
}
