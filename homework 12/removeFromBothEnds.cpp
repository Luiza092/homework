#include <iostream>
#include <deque>

void removeFromBothEnds(std::deque<int>& deq, int K){
    for(int i = 0; i < K; ++i){
        if(deq.empty()){
            return;
        }
        deq.pop_front();
        std::cout << deq.size() << "\n";
        for(int i = 0; i < deq.size(); ++i) {
            std::cout << deq[i] << " ";
        }
        std::cout << "\n";
        if(deq.empty()){
            return;
        }
        deq.pop_back();
        std::cout << deq.size() << "\n";
        for(int i = 0; i < deq.size(); ++i) {
            std::cout << deq[i] << " ";
        }
        std::cout << "\n";
    }
    
}

int main()
{
    std::deque<int> d = {1, 2, 3, 4, 5, 6};
    removeFromBothEnds(d, 2);
    
    return 0;
}