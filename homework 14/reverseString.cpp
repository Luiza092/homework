#include <iostream>
#include <stack>
#include <string>

void reverseString(std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        st.push(c);
    }

    for (size_t i = 0; i < s.size(); ++i) {
        s[i] = st.top();
        st.pop();
    }
}
int main() {
    std::string s = "Hello";
    reverseString(s);
    std::cout << s << '\n';  // olleH
    return 0;
}