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

void removeDuplicates(ListNode* head) {
	if(head == nullptr) return;

	ListNode* current = head;
	while(current->next != nullptr) {
		if(current->data == current->next->data) {
			ListNode* temp = current->next;
			current->next = temp->next;
			delete temp;
		} else {
			current = current->next;
		}
	}
}

void print(ListNode* head) {
	while(head != nullptr) {
		std::cout << head->data << " -> ";
		head = head->next;
	}
	std::cout << "nullptr";
}

int main() {
	ListNode* head = createList(1, 1, 3, 3, 4);
	print(head);
	std::cout << std::endl;
	removeDuplicates(head);
	print(head);


	return 0;
}