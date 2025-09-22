#include <iostream>
#include <vector>

void print(const std::vector<int> &v){
    for(int x : v){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

std::vector<int> mergeSortedVectors(const std::vector<int> &v1, const std::vector<int> &v2){
    std::vector<int> result;
    result.reserve(v1.size() + v2.size()); 

    std::size_t i = 0, j = 0;

    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            result.push_back(v1[i]);
            i++;
        }else{
            result.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()){
        result.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()){
        result.push_back(v2[j]);
        j++;
    }

    return result;
}

int main(){
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};

    std::vector<int> merged = mergeSortedVectors(vec1, vec2);

    std::cout << "Merged: ";
    print(merged);

    return 0;
}
