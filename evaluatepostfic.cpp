#include <iostream>
#include <stack>

using namespace std;
char NextToken(string e)
{
    static int i = 0;
    return (e.at(i++));
}

int evaluate(string e)
{
    stack<int> st;
    for (char x = NextToken(e); x != '#'; x = NextToken(e))
    {
        if (x >= '0' && x <= '9')
            st.push(x - '0');
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c;
            if (x == '+')
                c = a + b;
            else if (x == '-')
                c = a - b;
            else if (x == '*')
                c = a * b;
            else
                c = a / b;
            st.push(c);
        }
    }
    return st.top();
}
int main()
{
    cout << evaluate("123+*#");
    return 0;
}