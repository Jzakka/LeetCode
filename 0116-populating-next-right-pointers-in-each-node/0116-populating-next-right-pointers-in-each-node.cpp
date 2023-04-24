class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return NULL;
        auto node = root;
        auto left = node;
        Node *start = NULL;
        while (left->left) {
            while (node) {
                if (start) {
                    start->next = node->left;
                    node->left->next = node->right;
                    start = node->right;
                } else {
                    node->left->next = node->right;
                    start = node->right;
                }
                node = node->next;
            }
            node = left->left;
            left = node;
            start = NULL;
        }
        return root;
    }
};