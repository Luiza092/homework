#include <iostream>

struct ListNode {
	int data;
	ListNode* next;

	explicit ListNode(int val) : data(val), next(nullptr) {}

};

bool hasCycle(ListNode* head) {
	ListNode* temp = head;
	while (temp != nullptr && temp->next != nullptr) {
		head = head->next;
		temp = temp->next->next;
		if(head == temp) return true;
	}
	
	return false;
}

int main() {
	ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
	std::cout << hasCycle(head) << std::endl;

    head->next->next = head->next;
    std::cout << hasCycle(head) << std::endl;

	return 0;
}