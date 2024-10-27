#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 比较函数，实现最小堆
struct Compare {
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // 创建一个优先队列（最小堆）
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    // 将每个链表的头节点加入堆
    for (auto list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    // 创建一个虚拟头节点，用于简化合并的操作
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();

        // 将当前最小值加入结果链表
        current->next = node;
        current = current->next;

        // 如果当前节点有下一个节点，则继续加入堆
        if (node->next) {
            minHeap.push(node->next);
        }
    }

    return dummy.next;
}

int main() {

    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* c = new ListNode(2);
    c->next = new ListNode(6);

    vector<ListNode*> lists = {a, b, c};

    ListNode* result = mergeKLists(lists);


    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}



//O(N*logK)
//堆 最小堆
//最大堆（Max Heap）：对于每一个节点，节点的值总是不小于其子节点的值。
//最小堆（Min Heap）：对于每一个节点，节点的值总是不大于其子节点的值。
