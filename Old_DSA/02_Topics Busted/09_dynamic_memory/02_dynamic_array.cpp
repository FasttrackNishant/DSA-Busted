#include <iostream>
using namespace std;

int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    /*  int n;
      cin>>n;
      // int arr[n]; // BAD Pratice hain

      // dynamic allocation

      int *arr = new int[n];

      for (int i = 0; i < n; i++)
      {
          cin >> arr[i];
      }
      cout << getSum(arr, n);

  */

    // while(true)
    // {
    //     int i=5;
    // }
    // while ke andar aayega memory dega phir release kar dega and ye loop mein chalta rahega toh kisi bhi time mein sirf ek int ki hi memory li huyi hain

    while (true)
    {
        int *p = new int[5000000];
        cout << "running" << endl;
         delete p;
    }
    /*
    ab yaha pe gadbad yesi hai ki yaha memory saf nahi hoti automatically

    and delete is used to free the memory
    
    
    1.Void Pointers 
    2.refrence typecasting
    
    */
    return 0;
}