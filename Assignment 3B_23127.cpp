// B. Implement a program to convert an infix expression to prefix and postfix notation. 
// Evaluate both prefix and postfix expressions. 

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Returns precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// INFIX -> POSTFIX
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (c == ' ') continue;

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
// INFIX -> PREFIX
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfixOfReversed = infixToPostfix(infix);
    reverse(postfixOfReversed.begin(), postfixOfReversed.end());
    return postfixOfReversed;
}

// EVALUATE POSTFIX EXPRESSION
int evaluatePostfix(string postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (c == ' ') continue;
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result = 0;
            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (int i = 0; i < val2; i++) result *= val1;
                    break;
                }
            }
            st.push(result);
        }
    }
    return st.empty() ? 0 : st.top();
}

// EVALUATE PREFIX EXPRESSION (scan right to left)

int evaluatePrefix(string prefix) {
    stack<int> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (isOperator(c)) {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            int result = 0;
            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': {
                    result = 1;
                    for (int j = 0; j < val2; j++) result *= val1;
                    break;
                }
            }
            st.push(result);
        }
    }
    return st.empty() ? 0 : st.top();
}

//MAIN function

int main() {
    string infix;
    cout << "Enter an infix expression (single-digit operands, e.g. 3+4*2):\n";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix  = infixToPrefix(infix);

    cout << "\nInfix Expression   : " << infix << endl;
    cout << "Postfix Expression : " << postfix << endl;
    cout << "Prefix Expression  : " << prefix << endl;

    // Evaluation only works correctly if the expression is purely numeric
    bool isNumeric = true;
    for (char c : infix) {
        if (isalpha(c)) { isNumeric = false; break; }
    }

    if (isNumeric) {
        cout << "\nEvaluation of Postfix Expression : " << evaluatePostfix(postfix) << endl;
        cout << "Evaluation of Prefix Expression  : " << evaluatePrefix(prefix) << endl;
    } else {
        cout << "\n(Expression contains variables - evaluation skipped. "
                "Enter a purely numeric expression like 3+4*2 to evaluate.)\n";
    }

    return 0;
}
