#include <iostream>
using namespace std;
char tolowercase(char ch)
{
    // agar pehlese ho lowecase hain to thik
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;

    else
    { // nahi toh hume use lowecase mein karna padega
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))

        return 1;
    // valid hain

    return 0;
}
string removeuseless(string &s)
{

    string temp = "";

    for (int j = 0; j < s.length(); j++)

    {
        if (valid(s[j]))
        {
            temp.push_back(s[j]);
        }
    }
    return temp;
}

bool checkPalindrome(string s)
{
    int st = 0;
    int e = s.length() - 1;

    cout << s << endl;
    s = removeuseless(s);
    cout << s << endl;

    for (int j = 0; j < s.length(); j++)
    {
        s[j] = tolowercase(s[j]);
    }

    cout << s << endl;
    while (st <= e)
    {
        if (s[st] != s[e])
        {

            return 0;
        }
        else
        {
            st++;
            e--;
        }
    }
    return 1;
}
int main()
{
    string s = "Noon";

    cout << checkPalindrome(s);
}