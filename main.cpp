#include <iostream>
#include "tree.h"

int main(int argc, char** argv)
{
    printf("Hello, Word\n");

    string equation = "(3+5)-4";
    if(!checkEquation(equation))
    {
        cout << "fuk" << endl;
        return 1;
    }

    Tree oak (equation);
    string pine = oak.makePostFix(equation);

    cout << "POSTFIX! " << pine << endl;


    return 0;
}

/*Write a program that converts a fully parenthesized mathematical infix expression into an equivalent

postfix expression and then evaluates the postfix expression. A fully parenthesized expression is one

in which parenthesis surround every operator and its operands. For example, ((10 – (2 + 3)) * 2)

should be converted as 10 2 3 + - 2 *. Once the converted postfix expression is evaluated, the final

result must be displayed. The operations that allowed in this calculator are plus (+), minus (-),

multiply (*), divide (/) and power (^). However, your program must produce an error message when

the expression is invalid. For example, (2 + 3 and (2 + ) are invalid expressions.



NOTE: if you are going to build a tree (also called expression tree) from expression then read it post-order to get the expresson, make sure you get the prefix of expresson first then build a tree to make sure you have one to one mapping.

Here is an example:

Expression =  (A+B^C)*D+E^5
Step 1. Reverse the infix expression.
                5^E+D*)C^B+A(
Step 2. Make Every '(' as ')' and every ')' as '('
                 5^E+D*(C^B+A)
Step 3. Convert expression to postfix form using a stack (see below).*/
