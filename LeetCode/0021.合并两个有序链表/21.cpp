#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)  {}
    ListNode(int x) : val(x), next(nullptr)  {}
    ListNode(int x,ListNode *next) : val(x), next(next)  {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

    ListNode dummy;
    ListNode* tail = &dummy;

    while(l1 != nullptr && l2!=nullptr){
        if(l1->val <l2->val){
            tail ->next = l1;
            l1 = l1 ->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if(l1 != nullptr){
        tail->next = l1;
    }else{
        tail->next = l2;
    }

    return dummy.next;
}

void printList(ListNode* head){
    while(head !=nullptr){
        cout << head->val;
        if(head->next !=nullptr){
            cout<<"->";
        }
        head = head ->next;
    }
    cout << endl;
}


int main() {

    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));


    ListNode* mergedList = mergeTwoLists(l1, l2);


    printList(mergedList);

    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}