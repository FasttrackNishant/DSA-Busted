#include <iostream>
using namespace std;

void update(int *p)
{
    *p = (*p) * 2;
}

void increment(int **p)
{
    ++(**p);
}

int main()
{

    // 1
    // int first = 8;
    // int second = 18;
    // int *ptr = &second;
    // *ptr = 9;

    // cout << first << " " << second << endl;

    // //2
    //     int first = 6;
    //     int *p =&first;
    //     int *q = p;
    //     (*q)++;

    //     cout << first << endl;

    // 3
    // int first = 8;
    // int *p = &first;

    // cout << (*p)++ << endl;
    // cout << first << endl;

    // 4
    // agar int *p=0 likh rahe ho to initialize  p =&i eise kar lena

    // int *p = 0;
    // int first = 110;
    //  *p = first;
    // cout << *p << endl;
    // segmentation fault aayega

    // //5
    // int first =8;
    // int second=11;
    // int *third =&second;
    // first = *third;
    // *third = *third +2;

    // cout<<first<<" "<<second<<endl;

    // //6
    // float f =12.5;
    // float p = 21.5;
    // float *ptr = &f;
    // (*ptr)++;
    // *ptr =p;

    // cout<<*ptr<<" "<<f<<" "<<p;

    // //7
    //     int arr[5];
    //     int *ptr;
    //     cout << sizeof(arr) << " " << sizeof(ptr) << endl;
    //     return 0;

    // 8
    // int arr[] = {11, 21, 13, 14};
    // cout << *(arr) << " " << *(arr + 1) << endl;

    // 9
    // int arr[6] = {11, 12, 31};
    // cout << arr << " " << &arr << endl;

    // 10
    // int arr[6] = {11, 12, 31};
    // cout <<(arr+1) << endl;

    // 11
    // int arr[6] = {11, 12, 31};
    // int *p =arr;
    // cout <<p[2] << endl;
    // i.e. *(p+2)

    // 12
    //  int arr[]={11,12,13,14,15};
    //  cout<<*(arr)<<" "<<*(arr+3);

    // 13
    // here i am trying to update in symbol table which is not possible
    //  int arr[] ={11,21,31,41};
    //  int *ptr =arr++;
    //  cout<<*ptr<<endl;

    // // 14
    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;  //it will take ch to b
    // cout << *ptr << endl;

    //***~*~*~*~*~*~**
    // 15
    // char arr[] = "abcde";
    // char *p = &arr[0];
    // cout << p << endl;

    // 16
    // char arr[] = "abcde";
    // char *p = &arr[0];
    // p++;
    // cout << p << endl;

    // 17
    // char str[] = "string";
    // char *p = str;
    // cout << str[0] << " " << p[0] << endl;

    // 18
    //  int i=10;
    //  update(&i);
    //  cout<<i<<endl;

    // 19
    // int first = 110;
    // int *p = &first;
    // int **q = &p;
    // int second = (**q)++ + 9;
    // cout << first << " " << second << endl;

    // 20
    int first = 100;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    cout << first << " " << second << endl;

    // 21

    int num = 110;
    int *ptr = &num;
    increment(&ptr);
    cout << num << endl;
}