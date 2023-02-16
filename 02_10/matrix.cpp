#include <iostream>

void full_rand(int *arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        //arr[i] = rand() % 100 + 1; // 1 ... 100
        arr[i] = rand() % 100 - 50; // -50 ... 49
    }
}

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void print_arr(int **arr, const int y, const int x) {
    for (int i = 0; i < y; ++i) {

        for (int j = 0; j < x; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";

    }
}

int main() {
    srand(time(NULL));
    const int capasity = 3;
    int arr[capasity];
    // full_rand(arr, capasity);
    // print_arr(arr, capasity);

    const int x = 5, y = 5;
    int matrix[y][x];

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            matrix[i][j] = rand() % 100 + 1; // 1 - 100
        }
    }

    for (int i = 0; i < y; ++i) {

        for (int j = 0; j < x; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";

    }
    std::cout << "\n";


    int max = matrix[0][0], min = matrix[0][0];
    int max_line = 0, min_line = 0;
    int sum = 0, sum_line = 0; 
    int min_y = 0, max_y = 0; 
    int index_y = -1;
    int index_x = -1;
    int find_val;

    std::cout << "Input find value: ";
    std::cin >> find_val;

    
    for (int i = 0; i < y; ++i) {
        sum_line = 0;
        for (int j = 0; j < x; ++j) {
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
            
            if (matrix[i][j] == find_val) {
                index_y = i;
                index_x = j;
        }
            sum_line = sum_line + matrix[i][j];
        }

        sum += sum_line;
        if (max_line < (sum_line / x) || max_line == 0) {
            max_line = sum_line / x;
            max_y = i;
        }
        if (min_line > (sum_line / x) || min_line == 0) {
            min_line = sum_line / x;
            min_y = i;
        }
    }

    std::cout << "Min = " << min << "\n";
    std::cout << "Min line = " << min_y + 1 << "\n";
    std::cout << "Max = " << max << "\n";
    std::cout << "Max line = " << max_y + 1 << "\n";
    std::cout << "Avg = " << sum / (x * y) << "\n";

    if (index_y < 0) {
        std::cout << "Value: " << find_val << " not found!\n";
    } else {
        std::cout << "Value " << find_val << " - x: " 
        << index_x + 1 << " y: " << index_y + 1 <<"\n";
    }

    return 0;
}
