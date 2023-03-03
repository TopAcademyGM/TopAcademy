#include <iostream>
#include <string>

// конкатенация строк (склеивание)
void cat(char *str1, char *str2) {
    int i = 0;
    // Сначала мы дойдем до конца первой строки (до 0)
    while (str1[i] != '\0') {
        i++;
    }
    int j = 0;
    // Пока мы не дойдем до конца второй строки
    // мы будем вставлят в конец первой строки символы второй
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    // В конце обязательно должен быть 0 для обозначения конца строки
    str1[i] = '\0';
}

int main(int argc, char const *argv[])
{
    // char A = 65;
    // char A = 'A';
    // Любой символ в компьюторе это число
    // которое соответсвует этому символу в кодировке
    // в данном случае (ASCII)

    std::string str = "Hel";
    std::string str2 = "lo";
    str = str + str2; // конкатенация строк (склеивание)

    // Любая строка это массив символов (char) с \0 на конце
    char str_base[10] = "Hel";
    char str_base2[] = "lo";
    
    std::cout << str_base << "\n";

    cat(str_base, str_base2); // конкатенация строк (склеивание)
    // str_base = str_base + str_base2;

    std::cout << str_base << "\n";

    // char A = 'A';
    // char hi2[100] = {'H', 'e', 'l', 'l', 'o'};
    // const char hi1[5] = {'H', 'e', 'l', 'l', 'o'};


    // std::cout << hi2 << "\n";
    return 0;
}
