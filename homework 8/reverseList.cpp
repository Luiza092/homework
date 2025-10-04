#include <iostream>

struct ListNode {
	int data;
	ListNode* next;

	explicit ListNode(int val) : data(val), next(nullptr) {}

};

template <typename T>
ListNode* createList(T val) {
	return new ListNode(val);
}

template <typename T, typename ...Args>
ListNode* createList(T first, Args... args) {
	ListNode* head = createList(first);
	head->next = createList(args...);
	return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;  
        current->next = prev;  
        prev = current;       
        current = next;
    }

    return prev;
}

void print(ListNode* head) {
	while(head != nullptr) {
		std::cout << head->data << " -> ";
		head = head->next;
	}
	std::cout << "nullptr";
}

int main() {
	ListNode* head = createList(1, 2, 3, 4);
	print(head);
	std::cout << std::endl;
	head = reverseList(head);
	print(head);


	return 0;
}