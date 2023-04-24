class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) {
            return "[]";
        }
        queue<TreeNode *> Q;
        Q.push(root);

        string stringfied = "";

        while (!Q.empty()) {
            int qLen = Q.size();
            for (int i = 0; i < qLen; i++) {
                TreeNode *node = Q.front();
                Q.pop();

                if (node) {
                    stringfied += to_string(node->val);
                    Q.push(node->left);
                    Q.push(node->right);
                } else {
                    stringfied += "null";
                }
                stringfied += ',';
            }
        }

        return "["+stringfied+"]";
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "[]") {
            return nullptr;
        }

        vector<string> nodes;

        int s = 1, e = 2;
        for (; e < data.length()-1; e++) {
            if (data.at(e) == ',') {
                nodes.push_back(data.substr(s, e - s));
                s = e + 1;
            }
        }

        queue<TreeNode *> Q;
        auto root = new TreeNode(stoi(nodes.front()));
        Q.push(root);

        int idx = 1;

        while (idx < nodes.size()) {
            int window = Q.size() * 2;

            for (int i = 0; idx + i < nodes.size() && i < window; i++) {
                if (i & 1) {
                    if (nodes.at(i+idx) != "null") {
                        Q.front()->right = new TreeNode(stoi(nodes.at(i+idx)));
                        Q.push(Q.front()->right);
                    }
                        Q.pop();
                } else {
                    if (nodes.at(i+idx) != "null") {
                        Q.front()->left = new TreeNode(stoi(nodes.at(i+idx)));
                        Q.push(Q.front()->left);
                    }
                }
            }
            idx+=window;
        }
        return root;
    }
};