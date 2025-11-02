#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";
    cout << arr << endl; // prints first address
    cout << ch << endl;  // prints entire content

    char *c = &ch[0];

    cout << c << endl;
    // kya print karega entire stirng print kar dega

    /* yaha execution start huyi from the first address and stop hui at the null character but agar Null character nahi milta toh kya hota*/

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;
//ye acceptable
    char cha[6]="abcdf";
//risky & not acceptable 
    char *ca ="abcde";



    return 0;
}