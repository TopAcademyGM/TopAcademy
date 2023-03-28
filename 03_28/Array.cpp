#include <iostream>
#include <ios>
#include <string>

class MyString {
 private:
    char *data;
 public:
    MyString() {                   // конструктор по умолчанию
        data = nullptr;
    }
                                    // (запускается при создании без параметров)

    MyString(const MyString &other) : MyString(other.data) {    }
    // Запускаем конструктор explicit MyString(const char* str)
    // с аргументом other.data


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

    int length() const {
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


        // Пока оригинальная строка не закончилась
        // И Пока i не вышла за пределы нового размера
        for (int i = 0; this->data[i] != '\0' 
                    &&  i < new_size; i++) {
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


    // ПЕРЕГРУЗКА ОПЕРАТОРОВ

    MyString &operator=(const MyString& other) {
        resize(other.length());
        for (int i = 0; other.data[i] != '\0'; i++) {
            this->data[i] = other.data[i];
        }
        return *this;
    }
    MyString &operator=(const char *str) {
        int size = 0;
        while (str[size] != '\0'){
            size++;
        }
        resize(size);
        for (int i = 0; str[i] != '\0'; i++) {
            this->data[i] = str[i];
        }
        return *this;
    }

    MyString operator+(const MyString &other) {
        return *this + other.data;
    }
    
    // MyString operator+(int n) {

    // }
    MyString operator+(const char *str) {
        MyString new_str(*this);
        int old_size = new_str.length();
        int str_size = 0;
        while (str[str_size] != '\0') {
            str_size++;
        }
        new_str.resize(old_size + str_size);

        int i = old_size;
        for (int j = 0; str[j] != '\0'; j++) {
            new_str.data[i] = str[j];
            i++;
        }
        return new_str;
    }

    const char*get_data() const { return this->data; }
};

std::ostream &operator<<(std::ostream &out,
                         const MyString &str) {
    out << str.get_data();
    return out;
}


int main() {
    MyString mystr1;
    MyString mystr2("My second str");
    MyString mystr_copy(mystr2);
    std::string str = "Hello";
    std::cout << mystr2.at(3) << "\n";
    mystr2.at(3) = 'S';
    std::cout << mystr2.at(3) << "\n";
    // char char_str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};


    std::cout << mystr2 << '\n'; 
    mystr2.erase(2);
    mystr2.insert(2, '_');
    std::cout << mystr2 << '\n'; 
    mystr2.erase(9);
    mystr2.insert(9, '_');
    std::cout << mystr2 << '\n'; 
    mystr2 = mystr2 + ". It's my favarite";
    std::cout << mystr2 << '\n'; 

    mystr2 = "Hello My Best Friend!";
    std::cout << mystr2 << '\n'; 
    return 0;
}
