#pragma once
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Tree
{
private:
    int PEMDAS(char mander);

    class Node
    {
    private:
        Node *left;
        Node *right;
        int num;
        char op;

    public:
        Node();
        ~Node();
        void setOperator(char gimme);
        void setNumber(int num);

        Node* getLeft();
        Node* getRight();
        char getOp();
        int getNum();
        bool isNodeOperator();


        void setLeft(Node* give);
        void setRight(Node* give);

        void print(int depth = 0);
        int valueOf();
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
    int doMath();

    void print();




};

//Global shit

bool isOperator(char mander);

bool checkEquation(string equation);
