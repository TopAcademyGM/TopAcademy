#include <iostream>

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    const int capasity = 100;
    int arr[capasity];
    int size;

    std::cout << "Size = ";
    std::cin >> size;
    if (size < 0 || size > capasity) {  
        std::cout << "0 < Size <= " << capasity;
        return 1;
    }
    std::cout << "\n";

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    
    print_array(arr, size);

    int tmp;

    std::cout << "Add size = ";
    std::cin >> tmp;
    if (tmp <= 0 || tmp + size > capasity) {  
        std::cout << "0 < Size <= " << capasity;
        return 1;
    }
    std::cout << "\n";

        int buf = size;
        size = tmp + size;
        for (int i = buf; i < size; i++) {
            std::cin >> arr[i];
        }
    
    print_array(arr, size);
    
    return 0;
}
