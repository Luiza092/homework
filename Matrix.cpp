#include <iostream>
#include <string>
#include <stdexcept> 

template <typename T, size_t N, size_t M>
class Matrix {
private:
    T data[N][M]{};  

public:
    void set(int row,int col,const T& value) {
        if (row < 0 || row >= N || col < 0 || col >= M) {
            throw std::out_of_range("Index out of range");
        }
        data[row][col] = value;
    }

    T get(int row, int col) const {
        if (row < 0 || row >= N || col < 0 || col >= M) {
            throw std::out_of_range("Index out of range");
        }
        return data[row][col];
    }


    void print() const {
        for (size_t i = 0; i < N; i++) {
            for(size_t j = 0; j < M; j++){
                std::cout << data[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    
     Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    Matrix<int, 3, 2> matr1;
    matr1.set(0, 0, 3); matr1.set(0, 1, 6);
    matr1.set(1, 0, 4); matr1.set(1, 1, 8);
    matr1.set(2, 0, 5); matr1.set(2, 1, 10);
    matr1.print();
    Matrix<int, 3, 2> matr2;
    matr2.set(0, 0, 1); matr2.set(0, 1, 1);
    matr2.set(1, 0, 1); matr2.set(1, 1, 1);
    matr2.set(2, 0, 1); matr2.set(2, 1, 1);
    matr2.print();
    auto sum1 = matr1 + matr2;
    sum1.print();
    
    std::cout << "\n";
    
    Matrix<double, 2, 2> mtr1;
    mtr1.set(0, 0, 3.5); mtr1.set(0, 1, 6.8);
    mtr1.set(1, 0, 4.7); mtr1.set(1, 1, 8.2);
    mtr1.print();
    Matrix<double, 2, 2> mtr2;
    mtr2.set(0, 0, 1.5); mtr2.set(0, 1, 1.6);
    mtr2.set(1, 0, 1.9); mtr2.set(1, 1, 1.8);
    mtr2.print();
    auto sum2 = mtr1 + mtr2;
    sum2.print();
    
    std::cout << "\n";
    
    Matrix<std::string, 2, 3> m1;
    m1.set(0, 0, "H"); m1.set(0, 1, "m"); m1.set(0, 2, "fri");
    m1.set(1, 0, "ho"); m1.set(1, 1, "ar"); m1.set(1, 2, "you");
    m1.print();
    Matrix<std::string, 2, 3> m2;
    m2.set(0, 0, "i"); m2.set(0, 1, "y"); m2.set(0, 2, "end,");
    m2.set(1, 0, "w"); m2.set(1, 1, "e"); m2.set(1, 2, "?");
    m2.print();
    auto sum3 = m1 + m2;
    sum3.print();
    return 0;
}