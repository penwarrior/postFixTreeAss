#include "tree.h"
#include <stack>



bool isOperator(char mander)
{ //checks to see if a character is an operator
    if(mander == '+' || mander == '-'|| mander  == '/'|| mander == '*' || mander == '^')
    {
         return true;
    }
    else
    {
        return false;
    }

}


bool checkEquation(string equation)
{
    //make sure that the eqauation is valid - () in the right place, and all numbers and operators used correctly

    int firstP = 0, secondP = 0;

    for(unsigned int i = 0; i < equation.size(); ++i)
    {
        if(equation[i] == '(')
        {
            ++firstP;
        }
        if(equation[i] == ')')
        {
            ++secondP;
        }
        if(i != equation.size()-1)
        {
            if(isOperator(equation[i]))
            {
                if(isOperator(equation[i+1]) || equation[i+1] == ')')
                {
                    cout << "There is an issue with your opperator set up. Please re-enter your equation and try again." << endl;
                    return false;
                }
            }
        }

    }

    if(firstP != secondP)
    {
        cout << "The equation has some paranthesis errors, please try re-entering your equation." << endl;
        return false;
    }
    else
    {
        return true;
    }

    return false;
}

//Node Shit

Tree::Node* Tree::Node::getLeft()
{
    return left;
}

Tree::Node* Tree::Node::getRight()
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

Tree::Node::Node(char gimme)
{
    data = gimme;
    left = nullptr;
    right = nullptr;
}

Tree::Node::Node()
{
    left = nullptr;
    right = nullptr;
    data = '\0';
}

Tree::Node::~Node()
{

}

//Tree Shit
Tree::Node* Tree::getRoot()
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

string Tree::makePostFix(string eq)
{ //makes the checked equation into a postfix string
    //standard postfix notation is spaces
    string postEq, backwards;
    stack<char> pancake;
    int stringNumCounter = 0;

for(unsigned int f =0; f <=  eq.size(); ++f)
{
    backwards += eq[eq.size()-f];

    if(backwards[f] == '(')
    {
        backwards[f] = ')';
    }
    else if(backwards[f] == ')')
    {
        backwards[f] = '(';
    }


}
cout << "BACKWARDS! " << backwards << endl;



    for(unsigned int k =0; k< eq.size(); ++k)
    {
        string holdNum;

        for(unsigned int h = k; h < eq.size(); ++h)
        {
            //k+ length of holdNum after found an operator
            if(!isOperator(eq[h]) && eq[h] != '(' && eq[h] != ')')
            {
                holdNum += eq[h];
            }
            else
            {
                if (eq[h] != ')') {
                    pancake.push(eq[h]);
                }

                if (!holdNum.empty()) {
                    postEq += holdNum + " ";
                    stringNumCounter++;
                }
                break;
            }

        }

        if(stringNumCounter == 2)
        {
            postEq += pancake.top();
            pancake.pop();
            stringNumCounter--;
        }

        if(k == eq.size()-1)
        {
            postEq += holdNum + " ";
            stringNumCounter++;
        }
        k += holdNum.size();
    }

    while(!pancake.empty())
    {
        postEq += pancake.top();
        pancake.pop();
    }

    return postEq;
}


void Tree::fillTree(string postEq)
{

}

void Tree::doMath()
{

}
