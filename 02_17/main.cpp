#include <iostream>
#include "head.hpp"

int main() {
    std::string tmp_name;
    int tmp_pass;
    
    int error = 0;

    error = input_data(tmp_name, tmp_pass);
    if (error > 0) {
        error = find_user(tmp_name, tmp_pass);
        if (error > 0) {
            login(tmp_name);
        }
    }

    if (error < 0) {
        put_error(error);
    }
    return 0;
}