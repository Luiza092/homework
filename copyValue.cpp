#include <iostream>
#include <string>

template <typename T>
T copyValue(const T& value) {
    return value;
}

template <typename T>
T* copyValue(T* ptr) {
    if(!ptr){
         return nullptr; 
    }
    T* copy = new T;
    *copy = *ptr;   
    return copy;     
}

int main() {
    int x = 8;
    int y = copyValue(x);   
    std::cout << x << " " << y << "\n";

    std::string str1 = "sun";
    std::string str2 = copyValue(str1);
    std::cout << str1 << " " << str2 << "\n";

    int* px = new int(100);
    int* py = copyValue(px); 
    std::cout << *px << " " << *py << "\n";

    delete px;
    delete py;

    std::string* ps1 = new std::string("World");
    std::string* ps2 = copyValue(ps1);
    std::cout << *ps1 << " " << *ps2 << "\n";

    delete ps1;
    delete ps2;

    return 0;
}
