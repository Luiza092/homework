#include <iostream>
#include <string>
#include <stdexcept> 

template <typename T>
class Range {
private:
    T start;  
    T end;
    
public:

     Range(T s, T e) : start(s), end(e) {
        if (end < start) {
            throw std::invalid_argument("Error");
        }
    }

    bool contains(const T& value) const {
        return value >= start && value <= end;
    }

    int length() const {
        return end - start;
    }

    void print() const {
        std::cout << "[" << start << ", " << end << "]" << std::endl;
    }
};

 

int main() {
    Range<int> r1(3, 10); 
    r1.print();
    std::cout << r1.length() << "\n";
    std::cout << (r1.contains(7) ? "Yes" : "No") << "\n" ;
    std::cout << (r1.contains(20) ? "Yes" : "No");
    std::cout << std::endl;
    
    std::cout << "\n";
    
    Range<double> r2(1.2, 15.8); 
    r2.print();
    std::cout << r2.length() << "\n";
    std::cout << (r2.contains(56.8) ? "Yes" : "No") << "\n" ;
    std::cout << (r2.contains(2.5) ? "Yes" : "No");
    std::cout << std::endl;
    
    std::cout << "\n";
    
    Range<char> r3('a', 'k'); 
    r3.print();
    std::cout << r3.length() << "\n";
    std::cout << (r3.contains('j') ? "Yes" : "No") << "\n" ;
    std::cout << (r3.contains('i') ? "Yes" : "No");
    std::cout << std::endl;
    return 0;
}