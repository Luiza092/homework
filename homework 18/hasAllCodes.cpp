#include <iostream>
#include <set>
#include <string>
#include <cmath>

bool hasAllCodes(const std::string& s, int k) {
    if (k > s.size()) {
        return false;
    }

    std::set<std::string> st;

    for (int i = 0; i + k < s.size(); ++i) {
        st.insert(s.substr(i, k));
    }

    int n = 1 << k; //for 2^k

    return st.size() == n;
}

int main() {
    std::cout << hasAllCodes("00110110", 2) << '\n';  // 1 (true)
    // Двоичные коды длины 2: "00", "01", "10", "11"
    // Все найдены: "00" (индекс 0), "01" (индекс 1), "11" (индекс 5), "10" (индекс 3)

    std::cout << hasAllCodes("0110", 1) << '\n';      // 1 (true)
    // Двоичные коды длины 1: "0" и "1"
    // Оба присутствуют в строке

    std::cout << hasAllCodes("0110", 2) << '\n';      // 0 (false)
    // Двоичные коды длины 2: "00", "01", "10", "11"
    // Отсутствует "00"

    std::cout << hasAllCodes("0000000001011100", 4) << '\n';  // 0 (false)
    // Не все 16 возможных кодов длины 4 присутствуют

    return 0;
}