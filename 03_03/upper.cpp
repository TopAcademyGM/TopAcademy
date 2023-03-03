#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str;

    // Мы хотим перевести все символы которые считаем с cin (консоль) перевести в врхний регистр

    // std::cin >> str;
    std::getline(std::cin, str); // вместо чтения по слову считаем всю строчку

    int i = 0;
    while (str[i] != 0)
    {
        // str[i] = toupper(str[i]);
        // Если строка входит в диапозон от 'a' до 'z' (от 97 до 122)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 'a' - 'A'; // вычитаем разницу между 'a' и 'A'
        std::cout << char(str[i]);
        i++;
    }
    std::cout << "\n";
    return 0;
}
