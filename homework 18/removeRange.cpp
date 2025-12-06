#include <iostream>
#include <set>

int removeRange(std::set<int>& st, const int low, const int high) {
    int count = 0;

    for (auto it = st.begin(); it != st.end(); ) {
        if (*it >= low && *it <= high) {
            it = st.erase(it);
            ++count;
        }else {
            ++it;
        }
    }
    return count;
}

int main() {
    std::set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    int removed = removeRange(s, 5, 11);
    std::cout << removed << std::endl;

    return 0;
}