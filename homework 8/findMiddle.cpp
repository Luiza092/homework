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

ListNode* findMiddle(ListNode* head) {
	ListNode* temp = head;
	while (temp != nullptr && temp->next != nullptr) {
		head = head->next;
		temp = temp->next->next;
	}
	return head;
}

int main() {
	ListNode* head = createList(1, 2, 3, 4, 5, 6);
	ListNode* new_head = findMiddle(head);
	std::cout << new_head->data << std::endl;

	return 0;
}