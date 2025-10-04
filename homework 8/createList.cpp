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

void print(ListNode* head) {
	while(head != nullptr) {
		std::cout<<head->data<<" ";
		head = head->next;
	}
}

int main() {
	ListNode* head = createList(1, 2, 3, 4, 5);
	print(head);

	return 0;
}