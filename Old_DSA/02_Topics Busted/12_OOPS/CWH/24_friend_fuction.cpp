#include <iostream>
using namespace std;

class complex
{
    int a, b;

    /*
    1+4i
    2+6i
    -> sum  =3+10i
    */
public:
    void setnum(int n1, int n2)

    {
        a = n1;
        b = n2;
    }

friend complex sumcomplex(complex o1, complex o2);
    void printnum()
    {
        cout << "Your number is " << a << "+" << b << "i" << endl;
    }
};
complex sumcomplex(complex o1, complex o2)
{
    complex o3;

    o3.setnum((o1.a + o2.a), (o1.b + o2.b));

    return o3;
}

int main()
{
    complex c1, c2, sum;

    c1.setnum(3, 5);
    c2.setnum(4, 3);

    c1.printnum();
    c2.printnum();


    sum = sumcomplex(c1,c2);
  sum.printnum();
    return 0;
}