#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c;

public:
    int d, e;

    // declare kiya ki aage mil jayega aapko
    void setData(int a, int b, int c);

    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};
//set data karta kya hai 
void Employee :: setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c= c1;
}


 int main()
{
    Employee anuj; //created object of employee class
    anuj.setData(1,2,3);
/* //anuj.a = 78;  is yese nahi de sakte ye private hain isko sirf kisi class ka functin access kar sakta hain*/
anuj.d =34;
anuj.e = 56;

    anuj.getData();
    
        return 0;
}