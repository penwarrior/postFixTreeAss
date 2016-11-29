#include "tree.h"
#include <sstream>
#include <stack>

bool isOperator(char mander)
{ // checks to see if a character is an operator
    if (mander == '+' || mander == '-' || mander == '/' || mander == '*' || mander == '^') {
        return true;
    } else {
        return false;
    }
}

bool checkEquation(string equation)
{
    // make sure that the eqauation is valid - () in the right place, and all
    // numbers and operators used correctly

    int firstP = 0, secondP = 0;

    for (unsigned int i = 0; i < equation.size(); ++i) {
        if (equation[i] == '(') {
            ++firstP;
        }
        if (equation[i] == ')') {
            ++secondP;
        }
        if (i != equation.size() - 1) {
            if (isOperator(equation[i])) {
                if (isOperator(equation[i + 1]) || equation[i + 1] == ')') {
                    cout << "There is an issue with your opperator set up. Please "
                            "re-enter your equation and try again."
                         << endl;
                    return false;
                }
            }
        }
    }

    if (firstP != secondP) {
        cout << "The equation has some paranthesis errors, please try re-entering "
                "your equation."
             << endl;
        return false;
    } else {
        return true;
    }

    return false;
}

// Node Shit

Tree::Node*
Tree::Node::getLeft()
{
    return left;
}

Tree::Node*
Tree::Node::getRight()
{
    return right;
}

void Tree::Node::setLeft(Node* give)
{
    left = give;
}

void Tree::Node::setRight(Node* give)
{
    right = give;
}

void Tree::Node::setOperator(char gimme)
{
    op = gimme;
}
void Tree::Node::setNumber(int gimme)
{
    num = gimme;
}

Tree::Node::Node()
{
    left = nullptr;
    right = nullptr;
    op = '\0';
    num = 0;
}

Tree::Node::~Node()
{
}

char Tree::Node::getOp()
{
    return op;
}

int Tree::Node::getNum()
{
    return num;
}

bool Tree::Node::isNodeOperator()
{
    return op != 0;
}

void Tree::Node::print(int depth /* = 0 */)
{
    for (int i = 0; i < depth; ++i)
        cout << " ";
    if (isNodeOperator()) {
        cout << op << "\n";
    } else {
        cout << num << "\n";
    }

    if (left) {
        left->print(depth - 1);
    }
    if (right) {
        right->print(depth + 1);
    }
}

int Tree::Node::valueOf()
{
    if (isNodeOperator()) {
        int x, y;
        if (left) {

            x = left->valueOf();
        }
        if (right) {
            y = right->valueOf();
        }
        switch(op){
            case '+':
return x+y;
            break;
            case '-':
return x-y;
            break;
            case '*':
return x*y;
            break;
            case '/':
return x/y;
            break;
            case '^':
return pow(x,y);
            break;
        }
    }

    else {
        return num;
    }
    return 0;
}

// Tree Shit
Tree::Node*
Tree::getRoot()
{
    return root;
}

void Tree::setRoot(Node* give)
{
    root = give;
}

Tree::Tree(string equation)
{
    root = new Node;
}

Tree::~Tree()
{
}

Tree::Tree()
{
    root = nullptr;
}

void Tree::print()
{
    if (root) {
        root->print(20);
    }
}

string
Tree::makePostFix(string eq)
{ // makes the checked equation into a postfix string
    // standard postfix notation is spaces
    char x = 0, token = 0;
    stack<char> s;
    string postfix;
    for (unsigned int i = 0; i < eq.size(); ++i) {
        token = eq[i];
        if (isalnum(token)) {
            postfix += token;
        }

        else if (token == '(')
            s.push('(');
        else {
            if (postfix.back() != ' ') {
                postfix += ' ';
            }
            if (token == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                    postfix += ' ';
                }
                s.pop();
            } else {
                while (!s.empty() && PEMDAS(token) <= PEMDAS(s.top())) {
                    x = s.top();
                    s.pop();
                    postfix += x;
                    postfix += ' ';
                }
                s.push(token);
            }
        }
    }
    while (!s.empty()) {
        postfix += ' ';
        x = s.top();
        s.pop();
        postfix += x;
    }
    return postfix;
}

int Tree::PEMDAS(char mander)
{
    if (mander == '(')
        return 0;
    if (mander == '+' || mander == '-')
        return 1;
    if (mander == '*' || mander == '/' || mander == '%')
        return 2;
    return 3;
}

void Tree::fillTree(string postEq)
{
    stringstream ss(postEq);
    stringstream conv;
    string part;
    int num;
    stack<Node*> fat;

    while (!ss.eof()) {
        ss >> part;

        if (isOperator(part[0])) {
            Node* right = fat.top();
            fat.pop();
            Node* left = fat.top();
            fat.pop();

            fat.push(new Node);
            fat.top()->setOperator(part[0]);
            fat.top()->setLeft(left);
            fat.top()->setRight(right);
        } else {
            fat.push(new Node);
            conv.clear();
            conv.str(string());
            conv.str(part);
            conv >> num;
            fat.top()->setNumber(num);
        }
    }
    root = fat.top();
}

int Tree::doMath()
{
    return root->valueOf();
}
