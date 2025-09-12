#include <iostream>
#include <cstring> 

template <typename T>
bool isEqual(const T& a, const T& b) {
    return a == b;
}

template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) {
    if (a == nullptr || b == nullptr) return false;
    return std::strcmp(a, b) == 0;
}

int main() {
    int x1 = 1, x2 = 9, x3 = 1;
    std::cout << std::boolalpha;
    std::cout << isEqual(x1, x2) << "\n";
    std::cout << isEqual(x1, x3) << "\n"; 
    
    std::cout << std::endl;

    double d1 = 3.14, d2 = 3.14, d3 = 9.8;
    std::cout << isEqual(d1, d2) << "\n"; 
    std::cout << isEqual(d1, d3) << "\n"; 
    
    std::cout <<std::endl;

    const char* s1 = "Hello";
    const char* s2 = "Hi";
    const char* s3 = "World";
    std::cout << isEqual(s1, s2) << "\n"; 
    std::cout << isEqual(s1, s3) << "\n"; 
    std::cout << std::endl;
    return 0;
}
