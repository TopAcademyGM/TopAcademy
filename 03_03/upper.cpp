#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str;

    // std::cin >> str;
    std::getline(std::cin, str);

    int i = 0;
    while (str[i] != 0)
    {
        // str[i] = toupper(str[i]);
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 'a' - 'A';
        std::cout << char(str[i]);
        i++;
    }
    std::cout << "\n";
    return 0;
}
