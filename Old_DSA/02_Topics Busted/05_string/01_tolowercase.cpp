/*https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633

palindrom

koi ek type ki string jisa reverse bhi same aaye to palindrome


*/

#include <iostream>
using namespace std;

char tolowercase(char ch)
{

    if ((ch >= 'a' && ch <= 'z') ||(ch>='0' && ch <='9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
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
int main()
{
    char a[20];
    cout << "Enter string :-" << endl;
    ;
    cin >> a;
    int len = getlength(a);
    cout <<tolowercase('B');
    cout <<tolowercase('A');
    
    return 0;
}
