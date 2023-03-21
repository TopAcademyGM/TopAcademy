#include <iostream>
// struct - По умолчанию все public
// class - По умолчанию все private

// Прямоугольник
class Parent {
 protected:
    int a, b;
    // const int test;
 public:

    

    Parent(int a, int b) : a(a), b(b) {
        // this->a = a;
        // this->b = b;
    }

    void draw() {
        std::cout << a << " " << b << "\n";
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j){
                if (i == 0 || j == 0 
                || i == a - 1 || j == b - 1) {
                    std::cout << "*";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }
        
    }
};

// Квадрат
class Child : public Parent {
 public:
    Child(int a, int b) : Parent(a, b) {
        if (a != b) {
            std::cout << "Стороны должны быть ровны!\n";
            this->b = a; 
        }
    }
};

int main(int argc, char const *argv[])
{
    // Parent A(5, 10);
    // A.draw();

    Child B(4, 6);
    B.draw();
    return 0;
}
