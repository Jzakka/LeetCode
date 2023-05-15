class NestedIterator {
private:
    vector<int>::iterator it;
    vector<int> flatList;

    void preOrder(const NestedInteger& element){
        if (element.isInteger()) {
            flatList.push_back(element.getInteger());
            return;
        }

        for (auto &nestedElement: element.getList()){
            preOrder(nestedElement);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (const auto &item: nestedList){
            preOrder(item);
        }
        it = flatList.begin();
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != flatList.end();
    }
};