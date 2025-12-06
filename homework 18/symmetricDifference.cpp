#include <iostream>
#include  <vector>
#include <set>

std::vector<int> symmetricDifference(const std::vector<int>& array1,
    const std::vector<int>& array2) {
    std::set<int> st1(array1.begin(), array1.end());
    std::set<int> st2(array2.begin(), array2.end());

    std::vector<int> result;

    for (int c : st1) {
        if (st2.find(c) == st2.end()) {
            result.push_back(c);
        }
    }
    for (int c : st2) {
        if (st1.find(c) == st1.end()) {
            result.push_back(c);
        }
    }
    return result;
}

int main() {

    std::vector<int> arr1 = {1, 2, 3, 4};
    std::vector<int> arr2 = {3, 4, 5, 6};
    auto result = symmetricDifference(arr1, arr2);

    for (int x : result) {
        std::cout << x << " ";
    }

    std::cout << std::endl;
    return 0;
}