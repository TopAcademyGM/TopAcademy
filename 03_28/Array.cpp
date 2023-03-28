#include <iostream>
#include <string>

class MyString {
 private:
    char *data;
 public:
    MyString() {                   // конструктор по умолчанию
        data = nullptr;
    }
                                    // (запускается при создании без параметров)

    explicit MyString(const char* str) {    // констрктор с аргументом
        int size = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            size++;
        }
        data = new char[size + 1];
        for (int i = 0; i < size; i++) {
            data[i] = str[i];
        }
        data[size] = '\0';
    }
        // explicit для разделения конструктора и преобразования

    int length() {
        int len = 0;
        while(this->data[len] != '\0') {
            len++;
        }
        return len;
    }

    char &at(int index) {
        return this->data[index];
    }
    void print() {
        if (this->data != NULL) {
            std::cout << this->data << "\n";
        }
    }

    void resize(int new_size) { // Изменение вместимости массива
        char *new_data = new char[new_size + 1];
        new_data[new_size] = '\0';

        for (int i = 0; this->data[i] != '\0'; i++) {
            new_data[i] = this->data[i];
        }
        if (new_size - 1 > 0) {
            new_data[new_size - 1] = '\0';
        }

        char *tmp = this->data;
        this->data = new_data;
        delete tmp;
    }

    void insert(int index, char val) {
        int i = length();
        resize(i + 1);

        while (i >= index) {
            this->data[i+1] = this->data[i];
            i--;
        }
        this->data[index] = val;
    }

    void erase(int index) {  // удаление символа по индексу
        int i = index;
        while (this->data[i] != '\0') {
            data[i] = data[i+1];
            i++;
        }
    }
};

int main() {
    MyString mystr1;
    MyString mystr2("My second str");
    std::string str = "Hello";
    std::cout << mystr2.at(3) << "\n";
    mystr2.at(3) = 'S';
    std::cout << mystr2.at(3) << "\n";
    // char char_str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    mystr2.print();
    mystr2.erase(2);
    mystr2.insert(2, '_');
    mystr2.print();
    mystr2.erase(9);
    mystr2.insert(9, '_');
    mystr2.print();

    return 0;
}
