#pragma once
#include <string>
#include <iostream>

using namespace std;

class Tree
{
private:

    class Node
    {
    private:
        Node *left;
        Node *right;
        char data;

    public:
        Node();
        ~Node();
        Node(char gimme);

        Node* getLeft();
        Node* getRight();

        void setLeft(Node* give);
        void setRight(Node* give);
    };

    Node *root;


public:
    Tree();
    ~Tree();
    Tree(string equation);

    Node* getRoot();
    void setRoot(Node* give);
    string makePostFix(string eq);

    void fillTree(string postEq);
    void doMath();




};

//Global shit

bool isOperator(char mander);

bool checkEquation(string equation);
