class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> path = split(preorder);
        int idx = 0;

        return preOrder(path, idx) && idx == path.size()-1;
    }

    bool preOrder(const vector<string>& path, int& idx){
        if (idx >= path.size()) {
            return false;
        }
        if (path.at(idx) == "#") {
            return true;
        }

        bool leftTraversal = preOrder(path, ++idx);
        bool rightTraversal = preOrder(path, ++idx);

        return leftTraversal & rightTraversal;
    }

    vector<string> split(string preorder) {
        vector<string> elements;
        string element;
        int i = 0;
        for (; i < preorder.length(); i++) {
            if (preorder.at(i) == ',') {
                elements.push_back(element);
                element = "";
            } else {
                element += preorder.at(i);
            }
        }
        elements.push_back(element);
        return elements;
    }
};