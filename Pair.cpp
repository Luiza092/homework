#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(const T1& a, const T2& b) : first(a), second(b) {}
    void print() const {
        std::cout << "First: " << first << ", Second: " << second << std::endl;
    }

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, std::string> p1(18, "Hi");
    Pair<double, char> p2(3.14, '!');

    p1.print(); 
    p2.print();  

    return 0;
}
