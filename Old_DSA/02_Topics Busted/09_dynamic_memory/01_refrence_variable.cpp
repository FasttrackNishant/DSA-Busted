#include <iostream>
using namespace std;

void update1(int n)
{
    n++;
}
void update2(int &n)
{
    n++;
}

int &update3(int a)
{
    int a = 10;
    int &ans = a;
    return ans;
}
//yaha pe problem yesi hain ki a and ans ki seema sirf us functin tak hi hain lekin hum use bahar le ja rahe hai so ye ek bad pratice  hain

//same problem aayegi ptr mein
int * fun(int n )
{
    int *ptr = &n;
    return ptr; 
}
int main()
{
    int i = 5;

    int &j = i; // this is refrence variable

    int n = 10;
    cout << n << endl;
    update1(n);
    cout << "Update 1" << n << endl;
    update2(n);
    cout << "Update 2" << n << endl;

    cout << "Update 3" << update3(n);

    return 0;
}