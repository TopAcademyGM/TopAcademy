#include <iostream>
#include <unistd.h>

const int G_x = 30;
const int G_y = 10;

void rand_full(int matrix[][G_x]) {
    for (int i = 0; i < G_y; ++i) {
        for(int j = 0; j < G_x; ++j) {
            matrix[i][j] = rand() % 2;
        }
    }
}

void print_matrix(int matrix[][G_x]) {
    
    for (int i = 0; i < G_y; ++i) {
        for(int j = 0; j < G_x; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << "\n";
    }
}

int get_step_n(int n, int step, int G, const int steps[]) {
    int tmp = n + steps[step];
    if (tmp == -1) {
        tmp = G - 1;
    } else if (tmp == G) {
        tmp = 0;
    }
    return tmp;
}

const int steps_y[8] = {-1,  -1, -1,  0,
                         0,   1,  1,  1};
const int steps_x[8] = {-1,   0,  1, -1,
                         1,  -1,  0,  1};
int count_live_cells(int matrix[][G_x],
                    int y, int x) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int tmp_y = get_step_n(y, i, G_y, steps_y);
        int tmp_x = get_step_n(x, i, G_x, steps_x);

        if (matrix [tmp_y] [tmp_x] == 1) {
            count++;
        }
    }
    return count;
}

void copy_matrix(int matrix[][G_x], int copy[][G_x]) {
    for (int i = 0; i < G_y; ++i) {
        for(int j = 0; j < G_x; ++j) {
            copy[i][j] = matrix[i][j];
        }
    }
}
void next_generation(int matrix[][G_x]) {
    int tmp_matrix[G_y][G_x];
    copy_matrix(matrix, tmp_matrix);
    for (int i = 0; i < G_y; ++i) {
        for(int j = 0; j < G_x; ++j) {
            int count_life = count_live_cells(tmp_matrix, i, j);
            
            if (matrix[i][j] == 0 && count_life == 3) {
                matrix[i][j] = 1;
            }else if (matrix[i][j] == 1 && (count_life == 3 ||
                                            count_life == 2)) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0; 
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int matrix[G_y][G_x];
    // int matrix[G_y][G_x] {
    //     {0,0,1,0,0},
    //     {0,0,0,1,0},
    //     {0,1,1,1,0},
    //     {0,0,0,0,0},
    //     {0,0,0,0,0}
    // };

    rand_full(matrix);

    while (1)
    {
        // char next;
        print_matrix(matrix);
        next_generation(matrix);
        // std::cin >> next;
        sleep(1);
        system("clear");
    }
}