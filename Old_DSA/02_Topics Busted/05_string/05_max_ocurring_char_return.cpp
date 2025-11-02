/*https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1*/
#include <bits/stdc++.h>
using namespace std;

char getmaxoccur(string s)
{
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
    // crated a count array
    {
        char ch = s[i];
        // lower case
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;
}

int main()
{

    string s;
    cin >> s;
    cout << getmaxoccur(s);
    return 0;
}