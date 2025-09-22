#include <iostream>
#include <vector>

void print(const std::vector<int> &v){
    for (int x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

std::vector<int> createVectorFromInput(){
    std::vector<int> vec;
    int num;

    while (std::cin >> num && num != 0){ //0 for ending
        vec.push_back(num);
    }

    return vec;
}

int main(){
    std::vector<int> inputVec = createVectorFromInput();

    std::cout << "Size: " << inputVec.size() << '\n';
    std::cout << "Elements: ";
    print(inputVec);

    return 0;
}
