#include <iostream>
#include <stack>


// Dijkastra's 2-stack algorithm for expression evaluation
class Calculator {

private:
    std::stack<char> ops;
    std::stack<int> nums;

    bool isOperator(char c) {
        return c == '-' || c == '+' || c == '*' || c == '/';
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    void applyOp(char op) {
        int a = nums.top(); nums.pop();
        int b = nums.top(); nums.pop();
        switch(op) {
            case '+': nums.push(a + b); break;
            case '-': nums.push(a - b); break;
            case '*': nums.push(a * b); break;
            case '/': nums.push(a / b); break;
        }
    }

public:
    double Calculate(std::string s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isspace(c)) continue;

            else if (isdigit(c)) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                // if the iteration reaches the end of the string
                // or the character is not a digit
                i--;
                nums.push(num);
            }

            else if (c == '(') {
                ops.push(c);
            }

            else if (c == ')') {
                while (!ops.empty()) {
                    if(ops.top() != '(') {
                        applyOp(ops.top());
                    }
                    ops.pop();
                }
            }

            else if (isOperator(c)) {
                while(!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    applyOp(ops.top());
                    ops.pop();
                }
                ops.push(c);
            }
        }

        while (!ops.empty()) {
            applyOp(ops.top());
            ops.pop();
        }

        return nums.top();
    }
}; 


int main() {
    std::string s = "2 * (1+3)";
    Calculator c;
    double d = c.Calculate(s);
    std::cout << d << std::endl;
    return 0;
}
