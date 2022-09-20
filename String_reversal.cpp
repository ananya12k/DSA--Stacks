#include <iostream>
using namespace std;
class Stack
{
private:
    char st[5];
    int top;

public:
    Stack(/* args */);
    void push(char a)
    {
        top++;
        if (top <= 4)
        {
            st[top] = a;
        }
        else
            cout << "Stack Overflow";
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
            cout << "Stack is empty";
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << st[i] ;
        }
    }
    void reverse()
    {
        char b[5];
        for (int i = 0; i < 5; i++)
        {
            b[i] = st[4 - i];
        }
        for (int i = 0; i < 5; i++)
        {
            st[i] = b[i];
        }
    }
    int rev(int p)
    {
        int n = p, d, r = 0;
        while (n)
        {
            d = n % 10;
            r = r * 10 + d;
            n = n / 10;
        }
        return r;
    }
};

Stack::Stack(/* args */)
{
    top = -1;
}

int main()
{
    char c;
    Stack s;
    for (int i = 0; i < 5; i++)
    {
        cin>>c;
        s.push(c);
    }
    cout<< "" << endl;
    s.display();
    s.reverse();
    cout<< "" << endl;
    s.display();
    for (int i = 0; i < 5; i++)
    {
        s.pop();
    }
    int i;
    cout<< "\nEnter a no. to get its reverse" << endl;
    cin>>i;
    cout<< s.rev(i) << endl;
    return 0;
}