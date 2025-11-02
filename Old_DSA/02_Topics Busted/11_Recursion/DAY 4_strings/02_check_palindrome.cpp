#include <iostream>
using namespace std;

bool checkpalindrome(string str, int i, int j)
{
    // base condition
    if (i > j)
        return true;

    if (str[i] != str[j])
    {
        return false;
       
    } 
    else
    {
       return checkpalindrome(str, i + 1, j - 1);
    }
}
 
int main()
{
    string str = "addn";
    cout << checkpalindrome(str, 0, str.length() - 1);
    cout << endl;
    return 0;
}