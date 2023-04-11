#include <iostream>

template <typename T>
class my_list {
 private:
    struct node {
        T value;
        node *next;
        node *prev;

        node() : node(T()) {}
        explicit node(const T& value, 
                      node *next = nullptr,
                      node *prev = nullptr)
            : value(value), next(next), prev(prev) {}
    };

    node *head; // голова (первый элемент)
    node *tail; // хвост  (последний элемент)
    int size();
    
};

int main() {
    
    return 0;
}
