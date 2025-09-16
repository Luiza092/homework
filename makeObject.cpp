#include <iostream>
#include <string>
#include <utility> 

template <typename T, typename... Rest>
T makeObject(Rest&&... rest) {
    return T(std::forward<Rest>(rest)...);
}

class Person {
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(std::move(n)), age(a) {}

    void print(){
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

int main() {
    auto person = makeObject<Person>("Alice", 25);
    person.print();
    return 0;
}
