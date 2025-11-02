#include <iostream>
using namespace std;

void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
}
void upadate(int *p)
{
    p = p + 1;
    cout<<"infun "<<p<<endl;

    //it will chage for p in this funcion only  but
    //will change for *p as address is passed and it is upadated everywhere
}


//int getsum(int arr[], int size)
//or -> 
int getsum(int *arr, int size)
{
    cout<<sizeof(arr)<<endl;
    int sum =0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{/*
    int value = 5;
    int *p = &value;
    cout << "before " << p << endl;
    // print(p);
    upadate(p);
    cout << "after " << p << endl;
 */
 
int arr[6]={1,2,3,4,5,8};
//this will return whole sum
cout<<getsum(arr,6)<<endl;
//this will return only after index three remember to pass actual size
cout<<getsum(arr+3,3)<<endl;

    return 0;
}