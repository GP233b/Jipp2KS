
    /*
    Przygotuj szablon funkcji, który przyjmuje 2 parametry np. a i b.
    Funkcja ma byæ typu void i wypisywaæ wynik a+b.
    
    Przygotuj specjalizacje tej implementacji dla klasy string, wtedy wynik ma byæ równy
    string.length(a) + string.length(b)
    Za zadanie mo¿esz otrzymaæ maksymalnie 5 punktów
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