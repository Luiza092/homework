#include <iostream>

template <typename F, typename T>
void applyAndPrint(F f, const T& arg) {
    std::cout << f(arg) << "\n";
}

template <typename F, typename T, typename... Rest>
void applyAndPrint(F f, const T& first, const Rest&... rest) {
    std::cout << f(first) << "\n";     
    applyAndPrint(f, rest...);        
}

int square(int x) {
    return x * x;
}

int main() {
    applyAndPrint(square, 2, 4, 50);
    return 0;
}
