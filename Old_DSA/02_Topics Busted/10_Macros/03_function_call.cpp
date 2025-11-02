#include <iostream>
using namespace std;

void fun(int a, int b)
{
    a++;
    b++;
    cout << a << " " << b << endl;
}

inline int getMax(int &a, int &b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a = 10, b = 20;
    // fun(a,b);
    // cout << endl;
    int ans = 0;
    // if (a < b)
    // {
    //     ans = a;
    // }
    // else
    // {
    //     ans = b;
    // }
    // but ise mein to tertiary operator mein bhi toh likh sakta hu na

    // ab yaha ye double dboule likhbna pad raha hai to function banao

    // ans = (a < b) ? a : b;

ans = getMax(a,b);
cout<<ans<<endl;

//ab memory toh bachali but function call toh abhi bhi ja rahi hain ab is inline bana dete hain

a=a+5;
b=b+9;

//but ab yaha pe function use kiya toh memory use ho rahi hai double toh ise solve karne ke liye refrence variable use kiya

ans= getMax(a,b);
cout<<ans<<endl;
    return 0;
}