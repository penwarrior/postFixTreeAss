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
    stack s;
    string postfix;
  for(unsigned int i = 0; i < eq.size(); ++i)
  {
    if(isalnum(token))
      {
          postfix += token;}

    else
       if(token == '(')
           push(&s,'(');
       else
       {
         if(token == ')')
             while((x=pop(&s))!='(')
             printf("%c",x);
         else
         {
         while(priority(token)< =priority(top(&s)) && !empty(&s))
             {
             x=pop(&s);
             printf("%c",x);
             }
         push(&s,token);
         }
       }
  }
  while(!empty(&s))
    {
    x=pop(&s);
    printf("%c",x);
    }
getch();
}


void Tree::fillTree(string postEq)
{

}

void Tree::doMath()
{

}
