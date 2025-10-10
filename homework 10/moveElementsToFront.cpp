#include <iostream>
#include <forward_list>

void moveElementsToFront( std::forward_list<int> &fl, int K){
    std::forward_list<int> result{};
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while(curr != fl.end()){
        if(*curr == K){
            result.push_front(*curr);
            curr = fl.erase_after(prev);
        }else{
            ++prev;
            ++curr;
        }
    }
            
    for (auto i = result.begin(); i != result.end(); ++i) {
        fl.push_front(*i);
    }
            
    for(int x : fl){
        std::cout << x << ' ';
    }
    
    std::cout << '\n';
    
}


int main() {
    std::forward_list<int> fl = {1, 3, 2, 3, 4, 3};
    moveElementsToFront(fl, 3);
    
    return 0;
}
