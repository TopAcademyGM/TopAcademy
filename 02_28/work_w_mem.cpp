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

int main() {
    srand(time(NULL));
    int size;
    std::cout << "size = ";
    std::cin >> size;
    int *arr = new int[size];

    full_rand_arr(arr, size);
    // find_min_max(arr, size); // Поиск макимума/минимума
    // find_more_n(arr, size, n); // Вывести кол-во эл больше чем n
    // del_elem(&arr, size, index); // Удаление элемента по индексу
    // add_elem(&arr, size, index, val); // Добавление элемента по индексу
    int arr2[5] = {5,4,3,2,1};
    int size2 = 5;
    // add_arr_in_end(&arr, size, arr2, size2); // Добавление элементов массива arr2
    // в конец массива arr
    // arr = 1,2,3,4 size = 5  arr2 = -4,-3,-2,-1 size2 = 5
    // arr = 1,2,3,4,-4,-3,-2,-1 size1=size1+size2=10

    delete [] arr;
}