class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *prevNode = nullptr;
        auto curNode = head;

        while (senrigan(curNode, n) != nullptr) {
            prevNode = curNode;
            curNode = curNode->next;
        }

        if(!prevNode){
            return head->next;
        }
        prevNode->next = curNode->next;
        delete curNode;
        return head;
    }

    ListNode* senrigan(ListNode* cur, int n){
        auto temp = cur;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp;
    }
};
