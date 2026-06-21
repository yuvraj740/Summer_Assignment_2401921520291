class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void shiftElements() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        shiftElements();
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }

    int peek() {
        shiftElements();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};