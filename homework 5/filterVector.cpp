#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T> &v) {
    for (const T &x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

bool isEven(int x){
    return x % 2 == 0;
}

template <typename T, typename P>
std::vector<T> filterVector(const std::vector<T> &v, P pred){
    std::vector<T> result;
    for(const T &x : v){
        if(pred(x)){
            result.push_back(x);
        }
    }
    return result;
}



int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    std::vector<int> filtered = filterVector(vec, isEven);

    std::cout << "Filtered: ";
    printVector(filtered); 

    return 0;
}
