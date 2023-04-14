#include <iostream>
#include <vector>
#include <list>


template <typename Iter>
void print_cont(Iter begin, Iter end) {
    for (auto i = begin; i != end; ++i) {
        std::cout << *i << " "; 
    }
    std::cout << "\n"; 
}

template <typename IterType1, typename IterType2>
void replace_cont(IterType1 begin, IterType1 end,
IterType2 begin_from, IterType2 end_from) {
    auto i = begin;
    auto j = begin_from;
    while (i != end && j != end_from) {
        *i = *j;
        ++i;
        ++j;
    }
}

int main() {
    std::vector<int> arr = {1,2,3,4,5};
    std::list<int> list = {7,8,6,9};

    print_cont(arr.begin(), arr.end());
    print_cont(list.begin(), list.end());

    replace_cont(list.begin(), list.end(),
                 arr.begin(), arr.end());

    print_cont(arr.begin(), arr.end());
    print_cont(list.begin(), list.end());
    return 0;
}
