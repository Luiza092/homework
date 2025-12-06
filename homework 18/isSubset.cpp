#include <iostream>
#include <set>
#include <vector>

bool isSubset(const std::vector<int>& sub, const std::vector<int>& super){
    std::set<int> st;
    for(const int& x : super){
        st.insert(x);
    }
    for(int x : sub){
        if(st.count(x) == 0){
            return false;
        }
    }
    return true;
    
}

int main()
{
    std::vector<int> subset = {1, 3, 5};
    std::vector<int> superset = {1, 2, 3, 4, 5};
    std::cout << isSubset(subset, superset) << '\n';  // 1 (true)
    
    std::vector<int> subset2 = {1, 6};
    std::cout << isSubset(subset2, superset) << '\n';  // 0 (false)

    std::cout << std::endl;
    return 0;
}