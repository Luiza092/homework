#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int>> &groups){
    for(const auto &group : groups) {
        std::cout << "{ ";
        for(int x : group){
            std::cout << x << ' ';
        }
        std::cout << "} ";
    }
    std::cout << '\n';
}

std::vector<std::vector<int>> groupAdjacent(const std::vector<int> &v){
    std::vector<std::vector<int>> result;

    if(v.size() == 0){
        return result;
    } 

    std::vector<int> currentGroup;
    currentGroup.push_back(v[0]);

    for(size_t i = 1; i < v.size(); ++i){
        if(v[i] == v[i - 1]){
            currentGroup.push_back(v[i]);
        }else{
            result.push_back(currentGroup);
            currentGroup.clear();
            currentGroup.push_back(v[i]);
        }
    }

    result.push_back(currentGroup); 
    return result;
}

int main(){
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};

    std::vector<std::vector<int>> groups = groupAdjacent(vec);

    std::cout << "Groups: ";
    print(groups);

    return 0;
}
