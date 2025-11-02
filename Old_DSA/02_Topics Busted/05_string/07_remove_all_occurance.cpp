/*https://leetcode.com/problems/remove-all-occurrences-of-a-substring/*/

#include <string.h>

string removeoccuraces(string s, string part)
{
    // tab tak loop chalao jab tak s khatm nahi ho jata and the part milta rehta hain string mein

    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length())
    }
    return s;
}