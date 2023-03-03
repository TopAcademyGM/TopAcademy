#include <iostream>
#include <string>

void cat(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main(int argc, char const *argv[])
{
    // char A = 65;
    std::string str = "Hel";
    std::string str2 = "lo";
    str = str + str2;

    char str_base[10] = "Hel";
    char str_base2[] = "lo";
    
    std::cout << str_base << "\n";

    cat(str_base, str_base2);
    // str_base = str_base + str_base2;

    std::cout << str_base << "\n";

    // char A = 'A';
    // char hi2[100] = {'H', 'e', 'l', 'l', 'o'};
    // const char hi1[5] = {'H', 'e', 'l', 'l', 'o'};


    // std::cout << hi2 << "\n";
    return 0;
}
