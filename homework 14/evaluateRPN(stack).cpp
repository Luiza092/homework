#include <iostream>
#include <stack>
#include <vector>
#include <string>

int evaluateRPN(const std::vector<std::string>& tokens) {
    std::stack<int> st;

    for (const auto& t : tokens) {

        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else if (t == "/") st.push(a / b);
        }
        else {
            st.push(std::stoi(t));
        }
    }

    return st.top();
}

int main()
{
 std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    std::cout << evaluateRPN(expr) << '\n';  // 9
    // (2 + 1) * 3 = 9
 return 0;
}