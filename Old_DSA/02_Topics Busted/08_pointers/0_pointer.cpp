#include <iostream>
using namespace std;
int main()
{ /*
     int num = 5;
     int *ptr = &num;

     cout << "value of num is : " << *ptr << endl;
     cout << "address of num is:- " << ptr << endl;

     cout<<"size of num :"<<sizeof(num)<<endl;
     cout<<"size of ptr :"<<sizeof(ptr)<<endl;

     int *p =0;
     // cout<<*p; //segmentation fault

 */

    int num = 5;
    int a = num;
    a++; // no impact
         // cout << a;

    // this will increment num
    int num1 = 15;
    int *b = &num1;
    (*b)++;
    // cout << *b;

    // copying one ptr to another

    // int *ptr2 = b;
    // cout << b << endl;
    // cout << *ptr2 << endl;
    // cout << ptr2 << endl;

    // imp concept
    int i = 10;
    int *t = &i;
    // (*t)++; 
    *t = *t +1;
    cout << *t << endl;
    cout<<t<<endl;
    t++;
    cout<<t<<endl; // it gone to next 4 location
    //double 8 bit aage chala jata

    return 0;
}