#include <iostream>
#include <stdlib.h>

void repit(int n_repit, std::string line)
{
    while (n_repit > 0)
    {
        std::cout << line;
        n_repit--;
    }
}

void repit_n_lines(FILE *my_file)
{
    int n_lines = 0, n_repit = 0;
    std::string line = "";
    char buf;
    if (fscanf(my_file, "%d %d", &n_lines, &n_repit) == 2)
    {
        n_lines++;
        while (fscanf(my_file, "%c", &buf) > 0 &&
               n_lines > 0)
        {
            line += buf;

            if (buf == '\n')
            {
                n_lines--;
                repit(n_repit, line);
                line = "";
            }
        }
    }
    else
    {
        std::cout << "File data error!\n";
    }
}

int main(int argc, char const *argv[])
{
    FILE *my_file;
    char file_name[100];

    while (1)
    {
        std::cout << "Input file name: ";
        std::cin >> file_name;
        std::cout << "File " << file_name << ":\n";

        // my_file = fopen("test.txt", "r");
        my_file = fopen(file_name, "r");
        if (my_file != NULL)
        {
            repit_n_lines(my_file);
        }
        else
        {
            std::cout << "File error!\n";
        }
    }
    return 0;
}
