#include <iostream>
#include <string>

class Logger {
    int count; 

public:
    Logger(int spaces) : count(spaces) {}

    template <typename T>
    void log(const T& arg) const {
        print(arg);
    }

    template <typename T, typename... Rest>
    void log(const T& first, const Rest&... rest) const {
        print(first);
        log(rest...);
    }
    
private:
    template <typename T>
    void print(const T& arg) const {
        for (int i = 0; i < count; ++i) {
            std::cout << ' ';
        }
        std::cout << arg << "\n";
    }
};

int main() {
    Logger logger(9);
    logger.log("Hello", 19, 9.8, 'L');
    return 0;
}