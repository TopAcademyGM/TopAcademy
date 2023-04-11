#include <iostream>
#include <string>

// !! Контейнеры (Коллекции)
#include <vector>           // массив
#include <list>             // двусвязный список
#include <set>              // бинарное дерево
#include <unordered_map>    // словарь


void test_vector() {
    std::vector<int> array ({4,5,6,12});

    std::cout << "Vector\n";
    std::cout << "Cap: " << array.capacity()
              << " Size: "<< array.size() <<"\n";
    array.insert(array.begin(), 15);    // добавил на место begin 15
    array.erase(array.begin() + 1);     // удалил элемент begin + 1
    array.pop_back();                   // удалил последний элемент
    array.push_back(77);                // добавил в конец 77
    std::cout << "Cap: " << array.capacity()
              << " Size: "<< array.size() <<"\n";

    for (auto i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

void test_list() {
    std::list<int> array ({4,5,6,12});

    std::cout << "List\n";
    std::cout << " Size: "<< array.size() <<"\n";
    
    array.insert(array.begin(), 15);    // добавил на место begin 15
    array.erase(++array.begin());     // удалил элемент begin + 1
    array.pop_back();                   // удалил последний элемент
    array.push_back(77);                // добавил в конец 77
    std::cout << " Size: "<< array.size() <<"\n";
    

    for (auto i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}


void test_set() {
    std::set<int, std::greater<int>> array ({4,5,6,12});

    std::cout << "Set\n";
    std::cout << " Size: "<< array.size() <<"\n";
    
    array.insert(15);    // добавил 15
    array.erase(4);     // удалил элемент со значением 4
    // array.pop_back();                   // удалил последний элемент
    // array.push_back(77);                // добавил в конец 77
    std::cout << " Size: "<< array.size() <<"\n";
    

    for (auto i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}


void test_unordered_map() {
    std::unordered_map<std::string, int> array ({{"Ivan", 21}, {"Egor", 37},
                                                 {"Roma", 7}, {"Tolya", 19}});

    std::cout << "Map\n";
    std::cout << " Size: "<< array.size() <<"\n";
    array.insert({"Victor", 21});
    array.erase("Roma");
    array.insert({"Anton", 99});
    std::cout << " Size: "<< array.size() <<"\n";
    

    for (auto i = array.begin(); i != array.end(); ++i) {
        std::cout << "Key: " << i->first<< " Value: " << i->second << "\n";
    }
    std::cout << "\n";
}




int main()
{
    test_vector();
    test_list();
    test_set();
    test_unordered_map();
    return 0;
}
