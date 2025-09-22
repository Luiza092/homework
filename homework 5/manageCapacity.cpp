#include <iostream>
#include <vector>

void manageCapacity(std::vector<int> &v){
    std::cout << "Before\n";
    std::cout << " Size: " << v.size() << '\n';
    std::cout << " Capacity: " << v.capacity() << '\n';

    v.reserve(v.size() + 500);

    for (int i = 1; i <= 500; ++i){
        v.push_back(i);
    }

    std::cout << "After\n";
    std::cout << " Size: " << v.size() << '\n';
    std::cout << " Capacity: " << v.capacity() << '\n';
}

int main(){
    std::vector<int> vec; 

    manageCapacity(vec);

    return 0;
}
