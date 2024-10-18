#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* dummyHead = new  ListNode(0);
    ListNode* current = dummyHead;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry != 0){
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l1 != nullptr) ? l1->val : 0;

        int total = val1 +val2 +carry;
        carry = total / 10;
        current->next = new ListNode(total % 10);
        current = current->next;

        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;


    }

    return dummyHead->next;
}
};


void printList(ListNode* node){
    while (node != nullptr){
        std::cout << node->val;
        if(node->next != nullptr) std::cout << " -> ";
        node = node->next;
    }
    std::cout <<std::endl;
}

int main() {

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);


    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(8);

  
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    
    std::cout << "Result: ";
    printList(result);

    return 0;
}