#include <iostream>
using namespace std;
void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout <<"Move a disc from " << A <<" to " << C<<endl;
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    cout << "Enter for how many discs do you want to solve TOH problem: " << endl;
    int n;
    cin >> n;
    char a = 'A', b = 'B', c = 'C';
    TOH(n,a,b,c);
    return 0;
}