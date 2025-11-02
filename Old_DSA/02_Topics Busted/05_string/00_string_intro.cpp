#include <bits/stdc++.h>
using namespace std;

int getlength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reversestr(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{
    int arr[10]; // integer array
    char name[20];
    // name[2]='\0';
    // cout<<"Enter the string"<<endl;

    cin >> name;
    int len = getlength(name);
    cout<<len;
    reversestr(name, len);
    cout<<len;

    cout << "Reverse string is " << name;
    return 0;
} 