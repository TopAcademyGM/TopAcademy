#include <iostream>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int y = 10;
    const int max_y = 10;
    int x = 20;
    // int x = 20;
    int diff = -1;

    while (1) {
        for (int i = 0; i < y; i++) {
            for (int i = 0; i < x; i++) {
                std::cout << "*";
            }
            // std::cout << x << " " << y << "\n";
            std::cout << "\n";

        }
        usleep(10000);
        y = y + diff;
        x = x + diff;
        if (y == 0 || y == max_y) {
            diff = -diff;
        }
        system("clear");
    }
    
    return 0;
}
