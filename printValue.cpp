#include <iostream>
#include <string>

template <typename T>
void printValue(const T& value) {
    std::cout << value << std::endl;
}

template <>
void printValue<bool>(const bool& value) {
    std::cout << (value ? "true" : "false") << std::endl;
}

template <>
void printValue<char*>(char* const& value) {
    std::cout << '"' << value << '"' << std::endl;
}

template <>
void printValue<const char*>(const char* const& value) {
    std::cout << '"' << value << '"' << std::endl;
}

int main() {
    printValue(19);       
    printValue(9.8);
    printValue(true);
    printValue(false);
    printValue("Hi");
    
    char str[] = "World";
    printValue(str); 

    return 0;
}
