#include <iostream>
using namespace std;

void update(int **ptr2)
{
    // ptr2 = ptr2 + 1; 
    //kuch chage nahi hoga

    // *ptr2 = *ptr2 + 1;
    //change hoga

    **ptr2  = **ptr2 + 1;
}

int main()
{

    int num = 10;
    int *ptr = &num;
    int **ptr2 = &ptr;
    /*
    cout << ptr << endl;
    cout << ptr2 << endl;
    // ptr2 will store the address of ptr

    // to print the value of i
    cout << num << endl;
    cout << *ptr << endl;
    cout << **(ptr2) << endl;

    // to print 2nd value
    cout << &num << endl;
    cout << ptr << endl;
    cout << *ptr2 << endl;

    // to print the third value
    cout << &ptr2 << endl;
    cout << *ptr2 << endl;
    */
    cout << endl
         << endl;
    cout << "Before " << num << endl;
    cout << "Before " << ptr << endl;
    cout << "Before " << ptr2 << endl;
    update(ptr2); 
    cout << "After " << num << endl;
    cout << "After " << ptr << endl;
    cout << "After " << ptr2 << endl;
    cout << endl
         << endl;

    return 0;
}