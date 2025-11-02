#include <iostream>
#include <deque>

template <typename T>
void rotateDeque(std::deque<T>& deq, int K){
    int n = deq.size();
    if(n == 0) return;

    if(K == 0) return;

    if(K > 0){
        for(int i = 0; i < K; ++i){
            T val = deq.back();
            deq.pop_back();
            deq.push_front(val);
        }
    }else {
        for(int i = 0; i < -K; ++i){
            T val = deq.front();
            deq.pop_front();
            deq.push_back(val);
        }
        
    }
    
}

int main()
{
    std::deque<int> d = {1, 2, 3, 4, 5};
    rotateDeque(d, 2);
    for(int x : d){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    rotateDeque(d, -1);
    for(int x : d){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}