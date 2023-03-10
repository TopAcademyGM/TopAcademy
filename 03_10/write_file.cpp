#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{    
    FILE *my_file;
    char file_name[100];
    std::cout << "Input file name: ";
    std::cin >> file_name;
    std::cout << "File " << file_name << ":\n";
    my_file = fopen(file_name, "w");
    if (my_file != NULL) {
        std::string str;
        while (str != "end") {
            std::cin >> str;
            fprintf(my_file, "%s\n", str.c_str());
        }  
    }
    return 0;
}
