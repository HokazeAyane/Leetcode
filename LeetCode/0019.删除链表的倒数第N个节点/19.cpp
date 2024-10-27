#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0); // 创建一个虚拟头节点
        dummy.next = head;
        ListNode *first = &dummy, *second = &dummy;
        
        // 移动 first 指针 n + 1 步
        for (int i = 0; i < n + 1; ++i) {
            first = first->next;
        }
        
        // 同时移动 first 和 second 指针，直到 first 到达链表末尾
        while (first) {
            first = first->next;
            second = second->next;
        }
        
        // 删除倒数第 n 个节点
        second->next = second->next->next;
        
        return dummy.next; // 返回新头节点
    }
};

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 测试函数
int main() {
    // 创建示例链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    
    // 删除倒数第 2 个节点
    ListNode* result = solution.removeNthFromEnd(head, 2);
    printList(result); // 输出: 1 2 3 5

    return 0;
}



// dummy -> 1 -> 2 -> 3 -> 4 -> 5
// ^ 
// first, second  (都指向 dummy)


// dummy -> 1 -> 2 -> 3 -> 4 -> 5
//     ^    
//     second   (仍然指向 dummy)
//                   ^
//                    first  (现在指向 3)


// dummy -> 1 -> 2 -> 3 -> 4 -> 5
//                   ^
//                 second  (现在指向 3)


