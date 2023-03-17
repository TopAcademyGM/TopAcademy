#include <fstream>
#include <iostream>
#include <string>


// Функция для ввода имени файла
std::string input_file_name() {
    std::string name;

    std::cout << "Введите имя файла: ";
    std::cin >> name;
    return name;
}

int main() {
    // i - input (чтение)
    // f - file
    // stream - поток
    std::ifstream fin;                          // Создаем поток для чтения из файла
    std::string file_name = input_file_name();  // Сохраняем имя файла введенное пользователем
    fin.open(file_name);                        // Открываем файл на чтение

    // если файл открылся (good == true пока мы можем читать файл)
    if (fin.good()) {
        std::string full_file;          // создаем переменную куда сохраним все содержимое файла
        while (fin.good()) {            // пока файл можно читать 
            std::string tmp;            // переменная для сохранения одной строки из файла
            std::getline(fin, tmp);     // читаем по одной строке
            full_file += tmp + "\n";    // записываем строку с символом перевода строки
        }
        // o - output (запись, вывод)
        std::ofstream fout;
        fout.open(file_name);       // Открываем файл на запись (перезапись)
        int i = 0;
        while (full_file[i] != 0) {     // Пока строка не закончилась

            // если это не символ пробела и не таб записываем в файл
            if (full_file[i] != ' ' && full_file[i] != '\t') {
                fout << full_file[i];
            }
            i++;
        }
    } else {
        // Если файл не открылся
        std::cout << "file error!";
    }
    return 0;
}