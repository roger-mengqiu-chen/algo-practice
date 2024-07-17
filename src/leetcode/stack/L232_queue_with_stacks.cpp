#include <stack>
#include <iostream>


class MyQueue {
private:
    std::stack<int> stack1, stack2;
public:
    MyQueue() {

    }

    void push(int x) {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(x);
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int x = stack1.top();
        stack1.pop();
        return x;
    }

    int peek() {
        return stack1.top();
    }

    bool empty() {
        return stack1.empty();
    }
}; 


int main() {
    MyQueue q;
    q.push(1);
    q.push(3);
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.empty() << std::endl;
    return 0;
}
