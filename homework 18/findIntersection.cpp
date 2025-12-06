#include <iostream>
#include <set>
#include <vector>

std::vector<int> findIntersection(const std::vector<int>& a1, const std::vector<int>& a2){
    std::set<int> s1;
    for(const int& x : a1){
        s1.insert(x);
    }
    std::vector<int> result;
    for(int x : a2){
        if(s1.count(x)){
            result.push_back(x);
        }
    }
    return result;
    
}

int main()
{
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 4, 5, 6, 7};
    auto result = findIntersection(arr1, arr2);
    // result: {3, 4, 5}
    for(auto c : result){
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}