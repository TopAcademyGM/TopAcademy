#include <iostream>
#include <string>

class Student{
 private:
    int id;
    std::string name;
    int marks[10];

 public:
 // Конструкторы это функции которые 
 // вызываются при создании объекта

    // Конструктор по умолчанию
    Student() : id(0), name("Test"), marks() {}

    // Конструктор с потоков чтения (откуда будем считывать)
    explicit Student(std::istream &in) {
        std::cout << "Id: ";
        in >> this->id;
        std::cout << "Name: ";
        in >> this->name;
        std::cout << "Marks: ";
        for (int i = 0; i < 10; i++) {
            in >> this->marks[i];
        }
    }

    // Конструтор с аргументами параметрами
    Student(int id, std::string name, int marks[10]) {
        this->name = name;
        this->id = id;
        for (int i = 0; i < 10; i++) {
            this->marks[i] = marks[i];
        }
    }
    friend std::ostream &operator<<(std::ostream &out
                        , Student &student) {

        out << "Id: " << student.id;
        out << "; Name: " << student.name << "; Marks [ ";
        for (int i=0; i < 10; i++) {
            out << student.marks[i] << " ";
        }
        out << "]";
        return out;
    }
};

int main() {
    int m[10] = {2,2,2,2,2,2,2,2,2,2};

    Student Test;
    Student Gosha(std::cin);
    Student Stepan(2, "Stepan", m);

    std::cout << Test << "\n";
    std::cout << Gosha << "\n";
    std::cout << Stepan << "\n";
    return 0;
}
