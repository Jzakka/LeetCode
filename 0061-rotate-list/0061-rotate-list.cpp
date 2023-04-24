class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        for(auto node = head; node != nullptr;node = node->next, len ++);
        return len;
    }

    ListNode *at(ListNode* node, int idx){
        auto _node = node;
        for(int i = 0; i< idx;i++, _node = _node->next);
        return _node;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        if(head == nullptr) return nullptr;
        int len = length(head);
        // 절단점 = 마지막 인덱스 - (k % len)
        int cut = (len - 1) - (k % len);
        // 절단점을 null 과 연결
        auto cuttingPoint = at(head, cut);
        // 마지막을 처음과 연결
        auto last = at(head, len - 1);

        last->next = head;
        auto res = cuttingPoint->next;
        cuttingPoint->next = nullptr;
        return res;
    }
};