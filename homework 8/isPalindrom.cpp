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

bool isPalindrom(ListNode* head) {
	if(head == nullptr || head->next == nullptr) return true;

	ListNode* slow = head;
	ListNode* fast = head;
	while(fast->next != nullptr && fast->next->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* revList = reverseList(slow->next);

	ListNode* firstHalf = head;
	ListNode* secondHalf = revList;
	bool result = true;

	while(secondHalf != nullptr) {
		if(firstHalf->data != secondHalf->data) {
			result = false;
			break;
		}

		firstHalf = firstHalf->next;
		secondHalf = secondHalf->next;
	}

	slow->next = reverseList(revList);
	return result;
}

void print(ListNode* head) {
	while(head != nullptr) {
		std::cout << head->data << " -> ";
		head = head->next;
	}
	std::cout << "nullptr";
}

int main() {
	ListNode* head = createList(1, 2, 2, 1);
	print(head);
	std::cout << std::endl;
	std::cout << isPalindrom(head) << std::endl;

	return 0;
}