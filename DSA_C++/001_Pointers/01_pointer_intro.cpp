#include <iostream>
using namespace std;


int * fun()
{
    int a = 10;
    return &a;
}

int main() {
    
    int num = 5;
    int * ptr = &num;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<"Size of pointer"<<sizeof(ptr)<<endl;

    //bad practice
    int * p;
    cout<<*p<<endl;

    // pointing to memeory which doesn't exist
    // int *p1=0;
    // cout<<*p1<<endl;


    int num1 = 5;
    int a = num1;

    a++;
    //copy. bani hogi
    cout<<num1<<endl;


    int num2 = 5;
    int *b = &num2;

    (*b)++;
    cout<<num2<<endl;

    // ponter copy  
    int *c = b;

    cout<<"C pointing to "<<*c<<endl;

    int i = 10;
    int *math = &i;

    (*math)++;

    cout<<"Math is "<< *math<<endl;

    int check = 100;
    int *checkPtr = &check;

    cout<<"Check"<<check<<" "<<"CheckPtr"<<checkPtr<<endl;
    
    checkPtr++;
    cout<<"Check"<<check<<" "<<"CheckPtr"<<checkPtr<<endl;
    
    // Dangling pointer
    
    // with the function call which return addressBriefly share your internship / work experiences and impact made

    //  * b = fun();

    int arr[10] = {0,3,6,4,20};

    cout<<"Address of Arr. : " <<arr<<endl;

    cout<<"Address of 0 th element "<<&arr[0]<<endl;

    cout << "* of arr : " << *arr<<endl;

    cout<<"* of arr + 1 :  "<< *arr + 1<<endl;

    cout<<"* of (arr + 1) :  "<< *(arr + 1)<<endl;

    int index = 3; 
    cout<<"1 st " << arr[index]<<endl;
    cout<<"2 nd " << i[arr] <<endl;


    return 0;
}

