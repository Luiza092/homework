#include <iostream>

struct ListNode {
	int data;
	ListNode* next;

	explicit ListNode(int val) : data(val), next(nullptr) {}

};

ListNode* deleteValue(ListNode* head, int value) {
	if(head == nullptr) return nullptr;
	head->next = deleteValue(head->next, value);

	if(head->data == value) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	return head;
}

void print(ListNode* head) {
	while(head != nullptr) {
		std::cout<<head->data<<" ";
		head = head->next;
	}
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head = deleteValue(head, 3);
	print(head);

	return 0;
}