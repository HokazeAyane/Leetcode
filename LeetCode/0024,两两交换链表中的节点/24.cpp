#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x) ,next(nullptr) {}
};

ListNode* swapPairs(ListNode* head){

    if(!head || !head->next){
        return head;
    }

    ListNode* first = head;
    ListNode* second = head->next;

    first->next = swapPairs(second->next);

    second->next = first;

    return second;
}

// 我们以输入链表 [1, 2, 3, 4] 为例，演示递归是如何工作的。

// 初始链表
// 1 -> 2 -> 3 -> 4
// 递归过程
// 第一次调用 swapPairs

// 输入链表为 [1, 2, 3, 4]
// first 指向 1
// second 指向 2
// 递归调用: first->next = swapPairs(second->next), 即处理 [3, 4]
// 第二次调用 swapPairs

// 输入链表为 [3, 4]
// first 指向 3
// second 指向 4
// 递归调用: first->next = swapPairs(second->next), 即处理 []（空链表）
// 第三次调用 swapPairs

// 输入链表为空 []
// 基础条件判断: 由于链表为空或只有一个节点，直接返回 head（即 nullptr）
// 递归返回阶段
// 现在我们从递归的最深层开始返回，并在返回过程中进行交换操作：

// 从第三次调用返回：

// 返回值是 nullptr
// 状态: first 是 3，second 是 4，将 first->next 设为 nullptr
// 执行交换：second->next = first
// 返回 second（即新头节点 4）
// 当前子链表变为：
// 4 -> 3 -> nullptr
// 从第二次调用返回：

// 返回值是 [4->3->nullptr]
// 状态: first 是 1，second 是 2，将 first->next 设为 [4->3->nullptr]
// 执行交换：second->next = first
// 返回 second（即新头节点 2）
// 当前子链表变为：
// 2 -> 1 -> 4 -> 3 -> nullptr
// 从第一次调用返回：

// 最终返回值是 [2->1->4->3->nullptr]
// 总结
// 最终的链表是：

// 2 -> 1 -> 4 -> 3
// 代码追踪
// 我们再结合代码，逐步追踪递归调用和返回的过程：

// 第一次调用 swapPairs([1, 2, 3, 4])
// ListNode* first = head;     // first = 1
// ListNode* second = head->next; // second = 2
// first->next = swapPairs(second->next); // 递归处理 [3, 4]
// second->next = first;      // 将 1 和 2 节点交换
// return second;             // 返回 2 作为新的头节点
// 第二次调用 swapPairs([3, 4])
// ListNode* first = head;     // first = 3
// ListNode* second = head->next; // second = 4
// first->next = swapPairs(second->next); // 递归处理 []
// second->next = first;      // 将 3 和 4 节点交换
// return second;             // 返回 4 作为新的头节点
// 第三次调用 swapPairs([])
// if (!head || !head->next) {
//     return head;           // 直接返回 nullptr
// }
// 递归过程通过不断地拆分链表，并在返回过程中进行交换，最终达成链表中相邻节点的两两交换要求。这个递归过程非常直观，同时代码简洁有力。