#include <iostream>

std::string makeSentence(const std::string& arg) {
    return arg;
}

template <typename... Rest>
std::string makeSentence(const std::string& first, const Rest&... rest) {
    return first + ' ' + makeSentence(rest...);
}

int main() {
    std::cout << makeSentence("hello", "world") << std::endl;       
    std::cout << makeSentence("hi", "my", "friend") << std::endl;          
}
