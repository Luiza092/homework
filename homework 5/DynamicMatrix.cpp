#include <iostream>
#include <vector>

class DynamicMatrix{
private:
    std::vector<std::vector<int>> data;

public:
    DynamicMatrix(size_t rows, size_t cols){
        data.resize(rows, std::vector<int>(cols, 0));
    }

    int getElement(size_t row, size_t col) const {
        if (row < data.size() && col < data[0].size()) {
            return data[row][col];
        }
        throw std::out_of_range("Index out of range");
    }

    void setElement(size_t row, size_t col, int value) {
        if (row < data.size() && col < data[0].size()) {
            data[row][col] = value;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void addRow(){
        if(data.size() != 0){
            data.push_back(std::vector<int>(data[0].size(), 0));
        }else{
            data.push_back(std::vector<int>());
        }
    }

    void addColumn(){
        for(auto &row : data){
            row.push_back(0);
        }
    }

    void print() const{
        for(const auto &row : data){
            for(int x : row){
                std::cout << x << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main(){
    DynamicMatrix matrix(3, 3);

    matrix.setElement(1, 1, 42);  
    matrix.addRow();            
    matrix.addColumn();      

    std::cout << "Matrix:\n";
    matrix.print();

    return 0;
}

