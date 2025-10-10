#include <iostream>
#include <forward_list>

bool insertAfterPosition(std::forward_list<int> &fl, int pos, int x){
    int i = 0;
    auto it = fl.begin();
    while(i < pos && it != fl.end()){
        ++it;
        ++i;
    }
    if(it == fl.end()){
        return false;
    }
    
    auto edit = fl.insert_after(it, x);
    if(*edit == x){
        return true;
    }
    return false;
}

int main()
{
    std::forward_list<int> flist = {1, 2, 3, 4};
    std::cout << insertAfterPosition(flist, 1, 8) << "\n";

    for( int x : flist){
        std::cout << x << " ";
    }
    return 0;
}