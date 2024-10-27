struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x) ,next(nulptr){}
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* had,int k){
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* preGroupEnd = dummy;
        ListNode* current = head;

        int length = 0;
        while(current){
            current = current->next;
            length++;
        }

        current = head;
        while(length >= k ){
            ListNode* nextGroupStart = current;

            for(int i = 0 ; i< k - 1; ++i){
                nextGroupStart = nextGroupStart->next;
            }

            ListNode* nextHead = nextGroupStart->next;
            nextGroupStart->next = nullptr; //break link

            ListNode* reversedHead = reverseLinkedList(current);

            preGroupEnd->next = reversedHead;
            current->next = nextHead;

            preGroupEnd = current;
            current = nextHead;
            length -= k;
        }

        return dummy->next;
    }

private:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;

        while(current){
            ListNode* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        return prev;
    }

};