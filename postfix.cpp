#include <iostream>
#include <stack>
#include <string>

class Expression {

	std::string infix;
	std::string postfix;


	int sign_to_int(char op) {
		int p;
		if (op == '+' || op == '-') {
			p = 1;
		} else if (op == '*' || op == '/') {
			p = 2;
		} else {
			p = 0;
		}

		return p;

	}

	bool precedence(char op1, char op2) {
		int p1, p2;

		p1 = sign_to_int(op1);
		p2 = sign_to_int(op2);

		return p1>=p2;
		
	}

public:
	Expression() {
		infix="";
		postfix="";
	}

	~Expression() {}

	void getInfix() {
		std::cout << "Enter an expression: ";
		std::cin >> infix;
	}
	void showInfix() {
		std::cout << "Infix: " << infix << std::endl;
	}

	void showPostfix() {

		std::cout << "Postfix: " << postfix << std::endl;
	}

	void convertToPostfix() {
		std::stack<char> stk;
		postfix = "";

		for (int i = 0; i < infix.length(); i++) {
			char sym = infix[i];
			if (isalnum(sym)) {
				postfix += sym;
			} else if (sym == '(') {
				stk.push(sym);
			} else if (sym == ')') {
				while (!stk.empty() && stk.top() != '(') {

					postfix += stk.top();

					stk.pop();
				}

				stk.pop();
			} else {
				while (!stk.empty() && stk.top() != '(' && precedence(stk.top(), sym)) {
					postfix += stk.top();
					stk.pop();
				}
				stk.push(sym);
			}

		}
		while (!stk.empty()) {

			postfix += stk.top();
			stk.pop();
		}

	}

};


int main() {

	Expression expr;

	expr.getInfix();
	expr.showInfix();
	expr.convertToPostfix();
	expr.showPostfix();

}

