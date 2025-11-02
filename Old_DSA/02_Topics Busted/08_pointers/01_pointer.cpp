#include <iostream>
using namespace std;
int main()
{
  /*  int arr[10] = {2, 5, 6};
    cout << "address of first memory block : " << arr << endl;
    cout << &arr[0] << endl;
    // down thre wil print value at 0
    cout << arr[0] << endl;
    cout << *arr << endl;
    cout << *(&arr[0]) << endl;
    //    (*arr)++;
    cout << *arr << endl;

    //~~ below two is the formula
    cout << *(arr + 1) << endl; // value at index 1
    cout << arr[1];
    //~~
    cout<<"new method "<<endl;

    int i = 2;
    cout<<i[arr]; // chalega
*/
  /*
    int a[10] = {10, 20};
    int *p = &a[0];
    cout << sizeof(a) << endl; // 40
    cout << sizeof(*a) << endl;
    cout << sizeof(&a) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(&p) << endl;
  */

  /*
   // all three will print same
   int b[20] = {2, 3, 4};
   cout << &b[0] << endl;
   cout << &b << endl;
   cout << b << endl;
 cout<<endl;
   int *p = &b[0];

   cout << p << endl;
   cout << *p << endl;
   cout << &p << endl;

  */

  int arr[10];
  // ERROR
  //   arr = arr + 1;
 
 //ye chalega
  int *ptr = &arr[0];
  cout << ptr << endl;
  ptr++;
  cout << ptr << endl;

  return 0;
}