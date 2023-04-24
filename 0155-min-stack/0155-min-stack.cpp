class MinStack {
private:
    stack<pair<int, int>> valMinVal;
public:
    MinStack() {

    }

    void push(int val) {
        if (valMinVal.empty()) {
            valMinVal.push({val, val});
        } else {
            valMinVal.push({val, min(val, valMinVal.top().second)});
        }
    }

    void pop() {
        valMinVal.pop();
    }

    int top() {
        return valMinVal.top().first;
    }

    int getMin() {
        return valMinVal.top().second;
    }
};