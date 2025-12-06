#include <iostream>
#include <queue>
#include <vector>
#include <string>

std::vector<std::string> generateBinaryNumbers(int N) {
    std::vector<std::string> result;
    std::queue<std::string> q;

    q.push("1"); 

    for (int i = 0; i < N; ++i) {
        std::string curr = q.front();
        q.pop();

        result.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
    }

    return result;
}
int main() {
    auto result = generateBinaryNumbers(5);
    
    for (const auto& s : result)
        std::cout << s << " ";
    // result: {"1", "10", "11", "100", "101"}
    
    return 0;
}