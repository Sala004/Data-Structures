#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}


string convertToPostfix(string infix) {
    stack <char> stk;
    string postfix;
    for (int i = 0; i < infix.size(); i++) {
        if (isdigit(infix[i])) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop(); //pop '('
        }
        else {
            while (!stk.empty() && precedence(stk.top()) >= precedence(infix[i])) {
                if (stk.top() == '^' && infix[i] == '^') {
                    break;
                }
                postfix += stk.top();
                stk.pop();
            }
            stk.push(infix[i]);
        }
    }
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int main() {
    string str = "1+2*(3^4-5)^(6+7*8)-9";
    cout << "infix: " << str << endl;
    cout << "postfix: " << convertToPostfix(str) << endl;
    return 0;
}