#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

const int y = 11 * 1.5;
const int x = 40 * 1.5;

// Проверка положения рокетки
bool is_player(int j, int i, int pl_x, int pl_y) {
    if (j == pl_x) { // если x равен x рокетки
        if (i == pl_y || i == pl_y - 1 || i == pl_y + 1){ // если y равен одному из трех символов рокетки
            return true;
        }
    }

    return false;
}

// !!! СЛОЖНАЯ ФУНКЦИЯ ПЕРЕХВАТА

// перехват работы терминала на автоматический
bool kbhit() {
    static bool inited = false;
    int left;

    // заходит при первом вызове
    if (!inited) {
        termios t;
        tcgetattr(0, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(0, TCSANOW, &t);
        setbuf(stdin, NULL);
        inited = true;
    }

    // в left записывается true если была нажата любая кнопка
    ioctl(0, FIONREAD, &left);

    return left;
}
// !!! СЛОЖНАЯ ФУНКЦИЯ ПЕРЕХВАТА


// Функция вывода поля
void print_pole(int pl_l_x, int pl_l_y,
                int pl_r_x, int pl_r_y,
                int b_x, int b_y) {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (i == y - 1 || i == 0){
                    std::cout << "*"; // Нижняя и верхняя стенки
                } else if (j == x - 1 || j == 0){
                    std::cout << "*"; // Левая и правая стенки
                } else if (is_player(j, i, pl_l_x, pl_l_y)){
                    std::cout << "|"; // Левая рокетка
                } else if (is_player(j, i, pl_r_x, pl_r_y)){
                    std::cout << "|"; // Правая рокетка
                } else if (j == b_x && i == b_y){
                    std::cout << "o"; // Мяч
                } else {
                    std::cout << " "; // Пустота
                }
            }
            std::cout << "\n";
        }
        usleep(100000); // задержка влияющая на скорость изменения кадров
}

// Случайная генерация направления мяча по оси Y
int new_dir_ball_y() {
    return rand() % 3 - 1;
}

// Движение мяча
void move_ball(int &b_x, int &b_y,
                int &dir_b_x, int &dir_b_y,
                int pl_l_x, int pl_l_y,
                int pl_r_x, int pl_r_y) {
    
    // Передвижение в зависимости от направления
    b_x += dir_b_x;
    b_y += dir_b_y;

    // Проверка удара об ракетки
    if (is_player(b_x, b_y, pl_l_x + 1, pl_l_y)) {
        dir_b_x = -dir_b_x;
        dir_b_y = new_dir_ball_y();

    } else if (is_player(b_x, b_y, pl_r_x - 1, pl_r_y)) {
        dir_b_x = -dir_b_x;
        dir_b_y = new_dir_ball_y();

    } else if (b_x <= 0 || b_x >= x) { // ГОООЛ!!!!

        b_x = x / 2;
        // Изменение счета

    } else if (b_y == 1 || b_y == y - 2) { // Удары об нижнюю и верхнюю границы
        dir_b_y = -dir_b_y;
    }
}

// Обработка нажатий с клавиатуры
int input(int &pl_l_x, int &pl_l_y,
          int &pl_r_x, int &pl_r_y,
          int b_y) {
char move = 0;
    if (kbhit()) {
        std::cin >> move;
        if (move == 'a') {
            if (pl_l_y != 2)
                pl_l_y -= 1;
        }
        else if (move == 'z') {
            if (pl_l_y != y - 3)
                pl_l_y += 1;
        } else if (move < 0) {
            return -1;
        }

        if (pl_r_y > b_y) {
            if (pl_r_y != 2)
                pl_r_y -= 1;
        } else if (pl_r_y < b_y) {
            if (pl_r_y != y - 3)
                pl_r_y += 1;
        }
    }
    return 0;
}

int main () {
    srand(time(NULL));

    // положение левой ракетки
    int pl_l_x = 2;
    int pl_l_y = y / 2;

    // положение правой ракетки
    int pl_r_x = x - 3;
    int pl_r_y = y / 2;

    // положение мяча
    int b_x = x / 2;
    int b_y = y / 2;

    // направления мячя
    int dir_b_x = -1;
    int dir_b_y = new_dir_ball_y();

    while (1) {
        print_pole(pl_l_x, pl_l_y, pl_r_x, pl_r_y, b_x, b_y);
        input(pl_l_x, pl_l_y, pl_r_x, pl_r_y, b_y);
        move_ball(b_x, b_y, dir_b_x, dir_b_y,
             pl_l_x, pl_l_y, pl_r_x, pl_r_y);

        // Очистка экрана
        system("clear");
    }
    return 0;
}