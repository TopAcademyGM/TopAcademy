#include <iostream>
#include <string>


// void print_all_marks(Student *student) {
//     // std::cout << *(i + 3) << "\n";
//     // std::cout << i[3] << "\n";
//     // std::cout << (*student).name  << " : ";
//     std::cout << student->name  << " : ";
//     for (int i = 0; i < 10; ++i) {
//         std::cout << student->marks[i] << ", ";
//     }
//     std::cout << "\n";
// }

struct Student {

 private: // Приватные данные
    std::string name;
    int marks[10];

 public: // Публичные данные

    // Конструктор - функция которая вызывается при
    // создании объекта, для заполнения данных (полей)

    Student() { // Конструктор по умолчанию
        name = "Student";
        for (int i = 0; i < 10; ++i) {
            marks[i] = 0;
        }
    }
    Student(std::string name, int marks[10]) { // Конструктор с аргументами
        // this - объект из которого мы вызываем
        // функцию
        this->name = name;
        for (int i = 0; i < 10; ++i) {
            this->marks[i] = marks[i];
        }
    }

    void print_all_marks() {
        std::cout << name << " : ";
        for (int i = 0; i < 10; ++i) {
            std::cout << marks[i] << ", ";
        }
        std::cout << "\n";
    }

    std::string get_name() {return this->name;}
    void set_name(std::string new_name) {
        if (new_name.size() != 0) {
            this->name = new_name;
        }
    }
};

int main(int argc, char const *argv[]) {
    int marks[10] = {1, 4, 5, 5, 6, 3, 4, 5, 5, 6};
    Student Anton("Anton", marks);
    Student ListStud[10];
    
    Anton.print_all_marks();
    return 0;
}
