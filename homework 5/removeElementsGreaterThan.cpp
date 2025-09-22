#include <iostream>
#include <vector>

void print(const std::vector<int> &v){
    for (int x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int removeElementsGreaterThan(std::vector<int> &v, int limit){
    int count = 0;

    for (int i = v.size() - 1; i >= 0; --i){
        if (v[i] > limit){
            v.pop_back();   
            ++count;
        }else{
            break; 
        }
    }

    return count;
}

int main(){
    std::vector<int> v = {1, 3, 5, 7, 9};

    int removed = removeElementsGreaterThan(v, 5);

    std::cout << "Removed: " << removed << '\n';
    std::cout << "Result: ";
    print(v);

    return 0;
}
