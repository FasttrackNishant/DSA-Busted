/*https://leetcode.com/problems/valid-palindrome/

1. faltu char hatane hain
2. sab lowercase mein lana hain
3. palindrome check karna hain
*/

class Solution
{
private:
    bool validchar(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return 1;
        }
        return 0;
    }
    char toLowercase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch <= '9' && ch >= '0'))
        {
            return ch;
        }
        else
        {
            char temp;
            temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkpalindrome(string a)

    {
        int s = 0;
        int e = a.size() - 1;

        while (s <= e)
        {
            if (a[s] != a[e])
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

public:
    bool isPalindrome(string s)
    {

        string temp = "";

        for (int j = 0; j < s.length(); j++)
        {
           if(validchar(s[j]))
              {
                temp.push_back(s[j]);
              }
        }

        for (int j = 0; j < temp.size(); j++)
        {
            temp[j] = toLowercase(temp[j]);
        }

        return checkpalindrome(temp);
    }
};

class Solution
{

private:
    bool valid(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))

        {
            return 1;
        }
        return 0;
    }

    char toLowercase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch <= '9' && ch >= '0'))
        {
            return ch;
        }
        else
        {
            char temp;
            temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkpalindrome(string a)

    {
        int s = 0;
        int e = a.size() - 1;

        while (s <= e)
        {
            if (a[s] != a[e])
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

public:
    bool isPalindrome(string s)
    {

        // faltu character hatane hain

        string temp = "";

        for (int j = 0; j < s.length();)
        {
            if (valid(s[j]))
            {
                temp.push_back(s[j]);
            }
        }

        // lower casemein kardo

        for (int j = 0; j < temp.length(); j++)
        {
            temp[j] = toLowercase(temp[j]);
        }

        return checkpalindrome(temp);
    }
};