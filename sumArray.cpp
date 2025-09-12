#include <iostream>


template  <typename T>
void sumArray(T* array,int count){
    T sum{};
    for(int i = 0; i < count; i++){
        sum += array[i];
    }
    std::cout << sum <<std::endl;
}


int main()
{
    int arr[5] = {1, 2, 2, 5, 10};
    double arr1[2] = {15.2, 4.8};
    std::string arr2[3] = {"s", "u", "n"};
    sumArray<int>(arr, 5);
    sumArray<double>(arr1, 2);
    sumArray<std::string>(arr2, 3);
    return 0;
} 