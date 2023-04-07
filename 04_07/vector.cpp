#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
class Array {
 private:
    T* arr;
    int cap;
    int size;

 public:
    Array() {}
    Array(int n, T val) : cap(n), size(n) {
        arr = new T[this->cap];

        for (int i = 0; i < n; ++i) {
            arr[i] = val;
        }
    }
    Array(const Array &other) : cap(other.cap), size(other.size) {
        arr = new T[this->cap];

        for (int i = 0; i < other.size; ++i) {
            arr[i] = other->arr[i];
        }
    }
    // [1,2,3,4,5]
    Array(std::initializer_list<T> list) : cap(list.size()), size(list.size()) {
        this->arr = new T[this->cap];
        int j = 0;
        for (typename std::initializer_list<T>::iterator i = list.begin();
            i != list.end(); ++i) {
            this->arr[j] = *i;
            ++j;
        }
    }

    void print() {
        for (int i = 0; i < this->size; ++i) {
            std::cout << this->arr[i] << " "; 
        }
        std::cout << "\n"; 
    }

};


template <typename cont>
void print_conteiner(cont arr) {
    for (typename cont::iterator i = arr.begin();
        i != arr.end();
        i++) {
            std::cout << *i << " ";
    }
    std::cout << "\n";
}

int main() {
    Array<int> test_arr({3,2,1,5,6});
    test_arr.print();
    return 0;
}


// int main() {
//     int *arr = new int[5];
//     // arr[1] = 7;
//     std::vector<int> vec({1,2,3,4});
//     std::vector<int> vec();
//     vec.insert(vec.begin() + 2, 5);

//     std::list<int> my_list({9,8,7,6});

//     print_conteiner(vec);
//     print_conteiner(my_list);
//     std::sort(vec.begin(), vec.end());
//     print_conteiner(vec);
//     return 0;
// }
