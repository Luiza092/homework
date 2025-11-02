#include <iostream>
#include <deque>

void createAndFillDeque(int N){
    std::deque<int> deq;
    for(int i = 1; i <= N; i += 2){
        deq.push_back(i);
    }
    for(int i = 2; i <= N; i += 2){
        deq.push_front(i);
    }
    for(int i = 0; i < deq.size(); ++i){
        std::cout << deq[i] << " ";
    }
}

int main()
{
    createAndFillDeque(7);  
    std::cout << std::endl;

    return 0;
}