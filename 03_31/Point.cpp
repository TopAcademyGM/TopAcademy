#include <iostream>
class Point {
 private:
    int x, y;

 public:
    Point() : x(-15), y(-15) {} // 1. Конструктор по умолчанию
    Point(int x, int y) : x(x), y(y)  {} // 2. Конструктор с аргументами
    Point(const Point &other) : Point(other.x, other.y) {} // 3. Конструктор копирования 

    // 4. Оператор = (присвоение)
    Point &operator=(const Point &other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
    // 5. Оператор << (Отправка на чтение в поток)
    friend std::ostream &operator<<(std::ostream &out,
                        const Point &point) {
        out << "X: " << point.x << " Y: " << point.y; //<< "\n"
        return out;
    }
    // 6. Оператор + (сложение)
    Point operator+(const Point &other) const {
        Point new_obj(this->x + other.x, this->y + other.y);
        return new_obj;
    }
    int get_x() const { 
        // this->x = 10; // Функция const поэтому 
                         // поля не могут изменяться
        return x;
    }

    bool operator<(const Point &other) const {
        // if (this->x < other.x && this->y < other.y) {
        //     std::cout << "B < A\n";
        //     return true;
        // } 
        // return false;
        
        // return this->x < other.x && this->y < other.y;
        return this->x + this->y < other.x + other.y;
    }
    Point operator++(int) {
        Point tmp(*this);
        this->x++;
        this->y++;
        return tmp;
    }
    Point &operator++() {
        this->x++;
        this->y++;
        return *this;
    }

    // Переобразование в другой тип
    operator int() {
        return this->x + this->y;
    }

};

int main() {
    Point empty; // 1
    Point a(1, 17); // 2
    const Point b(a); // 3

    a = Point(10, 33); // 4

    std::cout << "Empty:\t" << empty << "\n";
    std::cout << "A:\t" << a << ".\n"; // 5
    std::cout << "A + B:\t" << b + a << "\n"; // 6
    // std::cout << b.operator+(a) << "\n";
    // std::cout << b.get_x() << "\n";

    if (b < a) {
        std::cout << "B < A\n";
    } else {
        std::cout << "B >= A\n";
    }

    std::cout << "\n\n";
    // int n = 0;
    std::cout << a++ << "\n";
    std::cout << a << "\n";
    std::cout << ++a << "\n";
    std::cout << a << "\n";

    double n = a;
    std::cout << n << "\n";
    
}