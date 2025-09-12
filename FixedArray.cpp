#include <iostream>
#include <string>
#include <stdexcept> 

template <typename T, size_t N>
class FixedArray {
private:
    T data[N];  

public:
    void set(int index, const T& value) {
        if (index < 0) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = value;
    }

    T get(int index) const {
        if (index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t size() const {
        return N;
    }

    void print() const {
        for (size_t i = 0; i < N; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    FixedArray<int, 4> arr;
    arr.set(0, 5);
    arr.set(1, 8);
    arr.set(2, 10);
    arr.set(3, 45);
    arr.print();
    FixedArray<double, 3> arr1;
    arr1.set(0, 23.5);
    arr1.set(1, 45.6);
    arr1.set(2, 9.8);
    arr1.print();
    FixedArray<std::string, 3> arr2;
    arr2.set(0, "array");
    arr2.set(1, "sun");
    arr2.set(2, "math");
    arr2.print();
    return 0;
}