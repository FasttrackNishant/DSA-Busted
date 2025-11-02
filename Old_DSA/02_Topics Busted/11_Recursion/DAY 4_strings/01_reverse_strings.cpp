#include <iostream>
#include <string.h>
using namespace std;

void reverse(string &str, int i, int j)
{
    // base case
    if (i > j)
    {
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;

    // baki rr sambhalega

    reverse(str, i, j);
}

int main()
{
    string str = "abcde";
    reverse(str, 0, str.length()-1);

    cout<< str<<endl;
    //ye pass by refrence se chalega nahi toh copy banegi dusre functin mein and the sare chages us copy mein honge main string waise ke waise hi rahegi
    return 0;
} 