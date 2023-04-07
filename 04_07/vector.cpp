#include <vector>
#include <list>
#include <iostream>

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
    int *arr = new int[5];
    // arr[1] = 7;
    std::vector<int> vec({1,2,3,4});
    vec.insert(vec.begin() + 2, 5);

    std::list<int> my_list({9,8,7,6});

    print_conteiner(vec);
    print_conteiner(my_list);
    return 0;
}
