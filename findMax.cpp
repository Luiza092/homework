#include <iostream>

template <typename P>
P findMax(P f, P a){
    if(f >= a){
        return f;
    }
    return a;
}


template<typename T,typename... Rest>
T findMax(T first, const Rest&... rest){
    return findMax(first, findMax(rest...)); 
}


int main()
{
    std::cout << findMax(2, 3, 4) << "\n";
    std::cout << findMax(2.5, 35.14, 4.8) << "\n";
}