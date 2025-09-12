#include <iostream>


template  <typename T>
void printElement(const T& elem){
    std::cout << elem << std::endl;
}


int main()
{
    printElement(5);
    printElement(1.52);
    printElement("Hello");

    return 0;
} 