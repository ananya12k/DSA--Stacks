#include <iostream>
// Implementing stack using array
// Stack can be implemented using linked list too
using namespace std;
class stack
{
private:
	int st[5];
	int top;
	static int size;

public:
	stack()
	{
		size = 3;
		top = -1;
	}
	int peep()
	{
		if (top == -1)
		{
			cout << "Stack underflow (empty)" << endl;
			return 0;
		}
		else
		{
			return (st[top]);
		}
	}
	bool is_Empty()
	{
		if (top == -1)
		{
			return true;
		}
		else
			return false;
	}
	void push(int a)
	{
		top++;
		if (top < size)
		{
			st[top] = a;
		}
		else
			cout << "Stack Overflow";
	}
	int pop()
	{
		if (top != -1)
		{
			int temp = st[top];
			top--;
			return temp;
		}
		else
			cout << "Stack is empty";
		return 0;
	}
	int Stack_CurrSize()
	{
		return (top + 1);
	}
};
int stack::size;
int main()
{
	stack s1;
	cout << "Pushing Elements to Stack" << endl;
	s1.push(10);
	s1.push(20);
	int top_ele = s1.peep();
	cout << "Topmost element " << top_ele << endl;
	int curr_size = s1.Stack_CurrSize();
	cout << "Current size of stack " << curr_size << endl;
	cout << "Retrieving Elements from Stack" << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	bool is_Stack_empty_or_not = s1.is_Empty();
	if (is_Stack_empty_or_not)
	{
		cout << "Stack is not empty" << endl;
	}
	else
	{
		cout << "Stack is empty" << endl;
	}
	return 0;
}
