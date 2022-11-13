#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    friend class Stack_Imp;
    Node()
    {
        next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};
class Stack_Imp
{
private:
    Node *top;

public:
    Stack_Imp(/* args */);
    ~Stack_Imp();
    void push(int x);
    int pop();
};

Stack_Imp::Stack_Imp(/* args */)
{
    cout << "Constructor called" << endl;
    top = NULL;
}
Stack_Imp::~Stack_Imp()
{
    cout << "Destructor called" << endl;
    delete top;
}
void Stack_Imp::push(int x)
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cout << "Memory Error" << endl;
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
int Stack_Imp::pop()
{
    if (top == NULL)
    {
        cout << "Element cannot be retrived as stack is empty" << endl;
        return 0;
    }
    else
    {
        Node *node = top;
        int x = node->data;
        node = NULL;
        top = top->next;
        delete node;
        return x;
    }
}
int main()
{
    Stack_Imp stack;
    stack.push(10);
    int x = stack.pop();
    cout << x << endl;
    return 0;
}