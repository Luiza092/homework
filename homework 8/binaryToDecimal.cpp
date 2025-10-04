#include <iostream>

struct ListNode {
	int data;
	ListNode* next;

	explicit ListNode(int val) : data(val), next(nullptr) {}

};

template <typename T>
ListNode* createList(T val){
    return new ListNode(val);
}

template <typename T, typename ...Args>
ListNode* createList(T first, Args... args){
    ListNode* head = createList(first);
    head->next = createList(args...);
    return head;
}

int binaryToDecimal(ListNode* head) {
    int result = 0;
    while (head != nullptr) {
        result = result * 2 + head->data; 
        head = head->next;
    }
    return result;
} 

int main() {
	ListNode* head = createList(1, 0, 1, 1);
	std::cout << binaryToDecimal(head) << std::endl;

	return 0;
}