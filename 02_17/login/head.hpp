#include <string>

// Ошибка < 0
// Успех > 0
void put_error(int error);

// Возвращаемые значения:
//  1   : Успешно
// -1   : Пользователь не найден
// -2   : Не верный пароль
// -3   : Системная ошибка
int find_user(std::string name, int pass);


// Возвращаемые значения:
//  1   : Успешно
// -3   : Системная ошибка
int input_data(std::string &name, int &pass);

void login(std::string name);


extern int test_name;