#include <iostream>
#include <set>
#include <vector>

std::vector<int> removeDuplicates(const std::vector<int>& numbers){
    std::set<int> num;
    for(int c : numbers){
        num.insert(c);
    }
    std::vector<int> result;
    for (int c : num) {
        result.push_back(c);
    }
    return result;

}

int main()
{
    std::vector<int> nums = {4, 2, 5, 2, 3, 4, 1};
    auto result = removeDuplicates(nums);
    for(auto c : result){
        std::cout << c << " ";
    }
    return 0;
}