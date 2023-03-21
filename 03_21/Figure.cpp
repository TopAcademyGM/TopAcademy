#include <iostream>

class Figure {                              // Класс Фигура
public:
    virtual int area() { return 0; }        // Площадь
};

class Circle : public Figure {              // Класс Круг наследуется от Фигуры
 private:
    double radius;
 public:
    Circle(double radius) : radius(radius) {}
    int area() {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Figure {
 private:
    double length;
    double width;
 public:
    Rectangle(double l, double w) : length(l), width(w) {}
    int area() {
        return length * width;
    }
};

int main() {
    Figure *SomeFigure = new Circle(5);
    Figure *AnotherFigure = new Rectangle(4, 3);

    std::cout << SomeFigure->area() << "\n";
    std::cout << AnotherFigure->area() << "\n";
    return 0;
}