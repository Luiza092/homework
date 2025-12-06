#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::string hotPotato(const std::vector<std::string>& players, int K) {
    std::queue<std::string> q;

    for (const auto& p : players) {
        q.push(p);
    }

    while (q.size() > 1) {

        for (int i = 0; i < K; ++i) {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    return q.front();
}

int main() {
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n';  // победитель
    
    return 0;
}