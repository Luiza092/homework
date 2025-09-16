#include <iostream>

template <typename T>
int countArgs(const T& arg) {
    return 1;
}

template <typename T, typename... Rest>
int countArgs(const T& first, const Rest&... rest) {
    return 1 + countArgs(rest...);
}

int main() {
    std::cout << countArgs(2, 15, 9) << "\n";          
    std::cout << countArgs(2.5) << "\n"; // 4
    std::cout << countArgs("hello", "world") << std::endl;          
}
