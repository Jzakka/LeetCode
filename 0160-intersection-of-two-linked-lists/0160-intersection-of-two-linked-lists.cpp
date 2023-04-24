class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto nodeA = headA;
        auto nodeB = headB;

        while (nodeA != nullptr && nodeB != nullptr) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        int diff = 0;
        bool aIsShorter = false;
        while (nodeB != nullptr) {
            aIsShorter = true;
            nodeB = nodeB->next;
            diff++;
        }
        while (nodeA != nullptr) {
            nodeA = nodeA->next;
            diff++;
        }
        nodeA = headA;
        nodeB = headB;
        if (aIsShorter) {
            while (diff--) {
                nodeB = nodeB->next;
            }
        } else {
            while (diff--) {
                nodeA = nodeA->next;
            }
        }

        while (nodeA != nullptr && nodeB != nullptr && nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        if (nodeA == nullptr || nodeB == nullptr) {
            return nullptr;
        }
        return nodeA;
    }
};