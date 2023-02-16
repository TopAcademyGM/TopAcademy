#include <iostream>

// Выводим массив
void print_array(int *arr, int size) { 
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    const int capasity = 100; // вместимость массива (максимальное количество)
    int arr[capasity]; // создаем массив с вместимостью 100 элементов
    int size; // размер массива (сколько элементов там находится фактически)

    std::cout << "Size = ";
    std::cin >> size; // вводим с консоли размер массива
    if (size < 0 || size > capasity) {  // проверям правильность и логичность ввода
        std::cout << "0 < Size <= " << capasity;
        return 1; // выходим из программы с кодом ошибки 1
    }
    std::cout << "\n";

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i]; // заполняем массив из консоли
    }
    
    print_array(arr, size);

    // Добавляем элементы в конец массива
    int tmp;
    std::cout << "Add size = ";
    std::cin >> tmp; // вводим количество элементов которые хотим добавить
    if (tmp <= 0 || tmp + size > capasity) {  
        std::cout << "0 < Size <= " << capasity;
        return 1;
    }
    std::cout << "\n";

    int buf = size; // сохраняем размер во временной переменной
    size = tmp + size; // изменяем размер на нынешний размер + tmp
    for (int i = buf; i < size; i++) { // заполняем массив от последнего заполненого до новой размерности
        std::cin >> arr[i];
    }
    
    print_array(arr, size);
    
    return 0;
}
