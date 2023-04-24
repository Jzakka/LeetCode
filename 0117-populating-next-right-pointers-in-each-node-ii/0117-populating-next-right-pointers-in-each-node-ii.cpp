class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return NULL;
        auto node = root;
        while (node) {
            Node *start, *horizon = NULL;
            start = NULL;
            while (node) {
                if (!horizon) {
                    if (node->left && node->right) {
                        start = node->left;
                        node->left->next = node->right;
                        horizon = node->right;
                    } else if (node->left) {
                        start = node->left;
                        horizon = node->left;
                    } else if (node->right) {
                        start = node->right;
                        horizon = node->right;
                    }
                } else {
                    if (node->left) {
                        horizon->next = node->left;
                        horizon = horizon->next;
                    }
                    if (node->right) {
                        horizon->next = node->right;
                        horizon = horizon->next;
                    }
                }
                node = node->next;
            }
            node = start;
            horizon = NULL;
        }
        return root;
    }
};