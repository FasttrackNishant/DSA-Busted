/*https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633

palindrom

koi ek type ki string jisa reverse bhi same aaye to palindrome


*/

#include <iostream>
using namespace std;


char tolowercase(char ch);
bool checkpalindrome(char a[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (tolowercase(a[s]) != tolowercase(a[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

int getlength(char a[])
{
    int count = 0;
    int i = 0;
    while (a[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

char tolowercase(char ch)
{

    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
int main()
{
    char a[20];
    cout << "Enter string :-" << endl;
    ;
    cin >> a;
    int len = getlength(a);
    cout << "Palindrome or not :- " << checkpalindrome(a, len) << endl;
    return 0;
}
