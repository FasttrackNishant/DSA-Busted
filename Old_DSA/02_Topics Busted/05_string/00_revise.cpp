#include <iostream>
using namespace std;

char tolowercase(char ch);
int getlenght(char name[])
{
    int i = 0;
    int count = 0;
    while (name[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

void reversestr(char name[], int len)
{
    int s = 0;
    int e = len - 1;

    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}
//to check is string valid or not
bool checkvalid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))

        return 1;
    // valid hain

    return 0;
    // invalid hain
}
//to remove extra from the string
string removeuseless(string s)
{

    string temp = "";

    for (int j = 0; j < s.length(); j++)

    {
        if (checkvalid(s[j]))
        {
            temp.push_back(s[j]);
        }
    }
    return s;
}

bool checkpalindrome(char a[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        if (tolowercase(a[s]) != tolowercase(a[e]))
            return 0;
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

/* ab is palindrom ke function ko case sensitive banane ke liye hume use lowercase mein ya phir uppercase mein lanna padega*/

char tolowercase(char ch)
{
    // agar pehlese ho lowecase hain to thik
    if (ch >= 'a' && ch <= 'z')
        return ch;

    else
    { // nahi toh hume use lowecase mein karna padega

        char temp = ch - 'A' + 'a';
        return temp;
    }
}
int main()
{
    char name[20];
    cin >> name;
    cout << name << endl;

    int length = getlenght(name);
    cout << length << endl;
    // reversestr(name, length);
    // cout << name;
    // cout<<endl;
    cout << "is string palindrome " << checkpalindrome(name, length);

    return 0;
}