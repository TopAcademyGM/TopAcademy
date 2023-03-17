#include <string>
#include <iostream>

struct test_struct {
    int h;
    int w;

};

struct player {
    int x;
    int y;

    void print_player_data() {
        std::cout << x << " " << y << "\n";
    }

    void down() {
        if (y > 0) {
            y--;
        }
    }
};


struct data {
    int d;
    int m;
    int y;

    int year_b(int y2) {
        int days = 0;
        days = (365 * (y2 - y));
        // std::cout << "Y" << days;
        return days;
    }

    
    int month_b(int m2) {
        int days = 0;
        days = (30 * (m2 - m));
        // std::cout << "M" << days;
        return days;
    }

    int days_b(int d2) {
        int days = 0;
        days = d2 - d;
        // std::cout << "D" << days;
        return days;
    }
    int days_betwen(int d2, int m2, int y2) {
        return year_b(y2) + month_b(m2) +
            days_b(d2);
    }

    int days_betwen(data other_data) {

        return 0;
    }
};

class test_class {

};

void print_player_data(const player& pl) {
    std::cout << pl.x << " " << pl.y << "\n";
}

int main()
{
    // char str[20];
    std::string cool_str = "";
    // cool_str += "Hello";
    // // str += "Hello";
    // std::cout << cool_str << "\n";
    
    // std::cout << cool_str.size() << "\n";

    // player pl_1;
    
    // pl_1.x = 100;
    // pl_1.y = 15;
    // pl_1.print_player_data();

    data test;
    test.d = 17;
    test.m = 3;
    test.y = 2000;

    std::cout << test.days_betwen(19, 5, 2001);

    return 0;
}
