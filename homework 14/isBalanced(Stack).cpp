#include <iostream>
#include <stack>

bool isBalanced(const std::string& s){
    std::stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else if(c == ')' || c == '}' || c == ']') {
            if(st.empty()) return false;

            char top = st.top();
            st.pop();

            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}
int main()
{
    std::cout << isBalanced("({[]})") << '\n';
    std::cout << isBalanced("([)]") << '\n';
    std::cout << isBalanced("{[}]") << '\n';
    return 0;
}