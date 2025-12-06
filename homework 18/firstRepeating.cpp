#include <iostream>
#include <set>
#include <vector>

int firstRepeating(const std::vector<int>& numbers) {
    std::set<int> st1;

    for (int c : numbers) {
        if (st1.find(c) != st1.end()) {
            return c;
        }
        st1.insert(c);
    }
    return -1;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 2, 5, 6, 3};
    std::cout << firstRepeating(nums) << std::endl;

    return 0;
}