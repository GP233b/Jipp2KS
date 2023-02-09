
    /*
    Przygotuj szablon funkcji, kt�ry przyjmuje 2 parametry np. a i b.
    Funkcja ma by� typu void i wypisywa� wynik a+b.
    
    Przygotuj specjalizacje tej implementacji dla klasy string, wtedy wynik ma by� r�wny
    string.length(a) + string.length(b)
    Za zadanie mo�esz otrzyma� maksymalnie 5 punkt�w
    */

#include <iostream>
#include <string>

template <typename T>
void myFunction(T a, T b) {
    std::cout << a + b << std::endl;
}


void myFunction(std::string a, std::string b) {
    std::cout << a.length() + b.length() << std::endl;
}

int main() {
    myFunction(1, 1);
    std::string a = "aaa";
    std::string b = "bbb";
    myFunction(a, b);
    return 0;
}