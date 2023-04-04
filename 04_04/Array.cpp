#include <iostream>
#include <fstream>

template <typename T>
class Array {
 private:
    T *arr;
    int size;

 public:
    // Конструктор по умолчанию
    Array() : Array(10) {}
    // Конструктор с аргументом размерности
    Array(int size) : size(size) {
        std::cout << "Hi!!!\n";
        this->arr = new T[size];
    }
    // Конструктор с аргументами источника массива и размерности
    Array(T* copy, int size) : Array(size) {
        for (int i = 0; i < size; ++i) {
            this->arr[i] = copy[i];
        }
    }
    // Коструктор чтения из потока
    Array(std::istream &in) {
        in >> size;
        std::cout << size << "\n";
        this->arr = new T[size];

        for (int i = 0; i < size; ++i) {
            in >> this->arr[i];
        }
    }

    void print_arr() {
        for (int i = 0; i < size; ++i) {
            std::cout << this->arr[i] << " ";
        }    
        std::cout << "\n";
    }
};


template <typename T>
void print_arr(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }    
    std::cout << "\n";
}

int main() {
    std::ifstream fin;
    fin.open("test");

    int i_arr[4] = {1,2,3,4};
    Array<int> my_arr(i_arr, 4);
    // Array<char> my_carr(std::cin);
    Array<int> my_carr(fin);
    Array<float> my_farr(15);

    my_arr.print_arr();
    my_carr.print_arr();
    my_farr.print_arr();
    // print_arr(i_arr, 4);
    // print_arr(c_mass, 4);
    // print_arr(f_mass, 4);

    return 0;
}
