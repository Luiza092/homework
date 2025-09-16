#include <iostream>
#include <utility>

template<typename T>
void print(T& arg) {
    std::cout << arg << " [lvalue]\n";
}

template<typename T>
void print(T&& arg) {
    std::cout << arg << " [rvalue]\n";
}

template<typename T>
void betterPrint(T&& arg) {
    print(std::forward<T>(arg));
}

template<typename T, typename... Rest>
void betterPrint(T&& first, Rest&&... rest) {
    print(std::forward<T>(first));
    betterPrint(std::forward<Rest>(rest)...);
}

int main() {
    int x = 42;
    betterPrint(x, 100, "hello");
    return 0;
}

