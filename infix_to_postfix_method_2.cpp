#include <iostream>
#include <stack>
using namespace std;
char NextToken(string e)
{
    static int i = 0;
    return (e.at(i++));
}

int isp(char ch)
{
    if (ch == '(')
    {
        return 4;
    }
    else if (ch == '+' || ch == '-')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 1;
    }
}
int icp(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 1;
    }
    else if (ch == '(')
    {
        return 0;
    }
}
void postfix(string str)
{
    stack<char> st;
    char y;
    st.push('#');
    for (char x = NextToken(str); x != '#'; x = NextToken(str))
    {
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            cout << x;
        }
        else if (x == ')')
        {
            for (y = st.top(), st.pop(); y != '('; y = st.top(), st.pop())
            {
                cout << y;
            }
        }
        else
        {
            for (y = st.top(), st.pop(); isp(y) < icp(x); y = st.top(), st.pop())
            {
                cout << y;
            }
            st.push(y);
            st.push(x);
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}
int main()
{
    string s = "A*(B+C)-D/E";
    postfix(s);
    return 0;
}