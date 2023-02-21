#include <iostream>

void full_arr_input(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";
        std::cin >> array[i]; // заполнение элементов с клавиатуры
        // array[i] = rand() % 100; // случайное значение от 0 до 99 
    }
}

int main(int argc, char const *argv[]) 
{
    srand(time(NULL));      // генерация коэфицента случайности 
    const int cap = 100;    // вместимость (сколько элементов в массиве может быть)
    int array[cap];         // создаем 100 элементов 
    int size;   
    std::cout << "Введите размер: ";
    std::cin >> size;       // Пользователь вводит размер массива

    full_arr_input(array, size); // заполнение массива с клавиатуры


    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " "; // вывод всех элементов массива
    }
    std::cout << "\n";
    return 0;
}


