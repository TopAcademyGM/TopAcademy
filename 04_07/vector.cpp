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
    typedef T value_type;
    class iterator;
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
            arr[i] = other.arr[i];
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

    void erase(int n) {
        for (int i = n; i < this->size - 1; ++i) {
            this->arr[i] = this->arr[i+1];
        }
        this->size -= 1;
    }


    void recap(int new_cap) {
        T* buf = new T[new_cap];

        for (int i = 0; i < new_cap && i < this->size; i++) {
            buf[i] = this->arr[i];
        }
        this->cap = new_cap;
        T* tmp = this->arr;
        this->arr = buf;
        delete [] tmp;
    }

    void insert(int n, T val) {
        if (this->size + 1 >= this->cap) {
            recap((this->cap + 1) * 2)
        }
        for (int i = size; i != n; --i) {
            this->arr[i] = this->arr[i-1];
        }
        this->size += 1;
        arr[n] = val;
    }

    iterator begin() {
        return iterator(this->arr);
    } 
    iterator end() {
        return iterator(this->arr + this->size);
    } 

    void print() {
        for (int i = 0; i < this->size; ++i) {
            std::cout << this->arr[i] << " "; 
        }
        std::cout << "\n"; 
    }


    ~Array() {
        delete [] this->arr;
    }

    class iterator{
     private:
        T* data;
     public:
        iterator(T* data) : data(data) {}
        T &operator*() {
            return *data;
        }
        iterator &operator++() {
            this->data++;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp {this->data};
            this->data++;
            return tmp;
        }
        iterator &operator--() {
            this->data--;
            return *this;
        }
        iterator operator--(int) {
            iterator tmp {this->data};
            this->data--;
            return tmp;
        }
        bool operator!=(const iterator &other) {
            return this->data != other.data;
        }
        iterator operator+(int n) {
            return iterator(this->data + n);
        }
        iterator operator-(int n) {
            return iterator(this->data - n);
        }
    };
};

template <typename cont>
void my_sort(cont &arr) {
    for (typename cont::iterator i = arr.begin();
        i != arr.end() - 1;
        i++) {
        for (typename cont::iterator j = i + 1;
            j != arr.end();
            j++) {
            if (*i > *j) {
                // std::cout << *i << " " << *j << "\n";
                typename cont::value_type tmp = *i;
                *i = *j;
                *j = tmp;
                // std::cout << *i << " " << *j << "\n";
                // print_conteiner(arr);
            }
        }
        
    }

}

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
    my_sort(test_arr);
    print_conteiner(test_arr);
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
