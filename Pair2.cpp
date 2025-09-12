#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b){}

    void print() const {
        std::cout << first << ", " << second << std::endl;
    }
};

template <typename T>
class Pair<T, T> {
private:
    T first;
    T second;

public:
    Pair(T a, T b) : first(a), second(b) {}

    void print() const {
        std::cout << "Pair of identical types: " << first << ", " << second << std::endl;
    }
};

int main() {
    Pair<int, double> p1(2, 9.4);
    p1.print();  

    Pair<std::string, std::string> p2("Hi", "World");
    p2.print(); 

    Pair<int, int> p3(20, 8);
    p3.print();

    return 0;
}
