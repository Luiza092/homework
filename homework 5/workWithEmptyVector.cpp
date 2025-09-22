#include <iostream>
#include <vector>

void workWithEmptyVector(){
    std::vector<int> vec;
    for(int i = 0; i < 10; ++i){
        vec.push_back(i);
        vec[i] = i + 1;
    }
    for(int i = 0; i < 10; ++i){
        std::cout << "Size: " << vec.size() << '\n';
        std::cout << "Capacity: " << vec.capacity() << '\n';
    }
    for(int i = 0; i < 10; ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    workWithEmptyVector();
    return 0;
}