#include <iostream>
#include <forward_list>

int removeAllOccurrences(std::forward_list<int> &fl, int rval) {
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    int count = 0;

    while (curr != fl.end()) {
        if (*curr == rval) {
            curr = fl.erase_after(prev);
            ++count;
        } else {
            prev = curr; 
            ++curr;
        }
    }

    return count;
}

int main() {
    std::forward_list<int> flist = {1, 2, 3, 2, 4, 2};
    int removed = removeAllOccurrences(flist, 2);

    for (int x : flist) {
        std::cout << x << " ";
    }
    std::cout << "\n" << removed << std::endl;
    return 0;
}
