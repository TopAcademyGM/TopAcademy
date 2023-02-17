#include <iostream>
#include <vector>

int b;

int test() {
    static int m = 1;

    std::cout << m << " ";
    m++;


    return m;
}

// float plus(float a, float b, float c) {
//     std::cout << "Float :";

//     return a + b;
// }

// int plus(int a, int b = 1) {
//     std::cout << "Int :";
//     return a + b;
// }

std::string plus(std::string a, std::string b, int t) {
    std::cout << "String :";
    return a + b;
}

template <typename type>
type plus(type a, type b) {
    return a + b;
}

template <typename type>
void print_arr(type *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {

    int array[5] = {1,2,3,4,5};
    float f_array[5] = {1.4f, 2, 3.6f, 4 ,5.77f};
    std::string s_array[5] = {"afd", "321", "12", "sgf", "gf"};

    print_arr(array, 5);
    print_arr(f_array, 5);
    print_arr(s_array, 5);



    // std::cout << "\n";
    // test();
    // test();
    // test();
    std::cout << "\n";

    std::string a = "aa";
    std::string b = "bb";

    std::cout << plus(1, 4) << "\n";

    std::cout << plus(5U, 6U) << "\n";

    std::cout << plus("dsf", "sdf", 1) << "\n";


    std::vector<int> arr = {1 ,2 ,3 ,4};
    for (int i = 0; i < 4; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.push_back(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

