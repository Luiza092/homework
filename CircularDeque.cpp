#include <iostream>
#include <stdexcept>

template <typename T>
class CircularDeque{
private:
    T* buffer;
    int size;
    int capacity;
    int head;
    int rear;
    
    void resize(){
        int newCapacity = capacity * 2;
        if (newCapacity == 0) newCapacity = 1;
        T* newBuffer = new T[newCapacity];
        
        for(int i = 0; i < size; ++i){
            newBuffer[i] = (*this)[i];
        }
        
        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
        head = 0;
        rear = size;
    }
    
public:
    explicit CircularDeque(int initialSize = 4) : capacity(initialSize),
        size(0), head(0), rear(0){
            buffer = new T[capacity];
        } 
        
    ~CircularDeque(){
        delete[] buffer;
    }
    
    bool isEmpty() const {
        return size == 0;
    }
    
    int getSize() const {
        return size;
    }
    
    void push_back(const T& value){
        if(size == capacity) resize();
        
        buffer[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }
    
    void push_front(const T& value){
        if(size == capacity) resize();
        
        head = (head - 1 + capacity) % capacity;
        buffer[head] = value;
        size++;
    }
    
    T pop_front(){
        if (isEmpty()) throw std::out_of_range("Deque is empty");
        T value = buffer[head];
        head = (head + 1) % capacity;
        size--;
        return value;
    }
    
    T pop_back(){
        if (isEmpty()) throw std::out_of_range("Deque is empty");
        rear = (rear - 1 + capacity) % capacity;
        T value = buffer[rear];
        size--;
        return value;
    }
    
    T front() const {
        if (isEmpty()) throw std::out_of_range("Deque is empty");
        return buffer[head];
    }
    
    T back() const{
        if (isEmpty()) throw std::out_of_range("Deque is empty");
        return buffer[(rear - 1 + capacity) % capacity];
    }
    
    T& operator[](int index) {
        if(index < 0 || index >= size) throw std::out_of_range("Index out of range");
        return buffer[(head + index) % capacity];
    }
    
    const T& operator[](int index) const{
        if(index < 0 || index >= size) throw std::out_of_range("Index out of range");
        return buffer[(head + index) % capacity];
    }
};

int main(){
    CircularDeque<int> dq;
    std::cout << "Is empty: " << dq.isEmpty() << '\n';  // true
    std::cout << "Size: " << dq.getSize() << '\n';      // 0

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);

    std::cout << "Front: " << dq.front() << '\n';  // 5
    std::cout << "Back: " << dq.back() << '\n';    // 20
    std::cout << "Size: " << dq.getSize() << '\n'; // 3
    
    return 0;
}
