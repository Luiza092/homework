#include <iostream>

template <typename P>
P sum(const P& arg){
    return arg;
}


template<typename T,typename... Rest>
T sum(T arg, const Rest&... rest){
    return arg + sum(rest...); 
}


int main()
{
    std::cout << sum(2, 3, 4) << "\n";
    std::cout << sum(2.5, 3.5, 4.5) << "\n";
    std::cout << sum(std::string("a"),std::string("b"), std::string("c")) << "\n";
}