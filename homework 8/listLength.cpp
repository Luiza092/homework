#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val) : data(val), next(nullptr) {}
        
};

size_t listLength(ListNode* head){
    size_t count = 0;
    while(head != nullptr){
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    std::cout<<listLength(head);
}