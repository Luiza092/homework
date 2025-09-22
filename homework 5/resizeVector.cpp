#include <iostream>
#include <vector>

template <typename T>
void print(const std::vector<T> &v){
    for (const T &x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void resizeVector(std::vector<T> &v, std::size_t size, const T &value){
    std::cout << "Before resize: ";
    print(v);

    v.resize(size, value);

    std::cout << "After resize:  ";
    print(v);
}

int main(){
    std::vector<int> v = {1, 2, 3};

    resizeVector(v, 5, 42);
    return 0;
}
