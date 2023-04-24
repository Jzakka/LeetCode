
class MyStack {
private:
    queue<int> Q;
    int temp = -1;
public:
    MyStack() {
    }

    void push(int x) {
        Q.push(x);
    }

    int pop() {
        int qSize = Q.size();
        for (int i = 0; i < qSize - 1; i++) {
            temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
        int top = Q.front();
        Q.pop();
        return top;
    }

    int top() {
        int qSize = Q.size();
        for (int i = 0; i < qSize - 1; i++) {
            temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
        int top = Q.front();
        Q.push(top);
        Q.pop();
        return top;
    }

    bool empty() {
        return Q.empty();
    }
};