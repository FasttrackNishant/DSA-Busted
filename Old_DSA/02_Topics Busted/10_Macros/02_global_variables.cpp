#include <iostream>
using namespace std;
// void b(int);

int score =14;
//this is global varible which can be used any where

void a(int &i)
{

    cout << i << endl;
    cout<<score<<endl;
    // b(i);
}

void b(int &i)
{
    cout << i << endl;
}
int main()
{
    int i = 5;

    {
        int i = 2;
        cout << i << endl;
    }
    a(i);
    cout << endl;
    cout<<score<<endl;
    return 0;
}