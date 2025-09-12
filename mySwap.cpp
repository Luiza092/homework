#include <iostream>


template  <typename T>
void mySwap(T first,T second){
    std::cout << first << " " << second <<std::endl;
    T temp;
    temp = first;
    first = second;
    second = temp;
    std::cout << first << " " << second <<std::endl;
}


int main()
{
    mySwap<int>(5,15);
    mySwap<std::string>("HELLO","WORLD");
    mySwap<double>(5.23,15.2);

    return 0;
} 