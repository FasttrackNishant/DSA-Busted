/*https://leetcode.com/problems/string-compression/*/

class Solution
{
    int compress(vector<char> &chars)
    {
        int i = 0;
        int ansIndex = 0;
        // ab ye answae index isliyye kyuki hum ise alag se populate nahi karna chahte extra space nahi leni hain

        int n = chars.size();

        while (i < n)
        {
            int j = i + 1;
            while (j < n && chars[i] == chars[j])
            {
                j++;
            }
            // yaha llop ke bahar kab aaye
            // vector khatn ho gaya ya new char mila
            // to ab ans store karte hain  unki count

            // old  char store kar le
            chars[ansIndex++] = chars[i];

            int count = j - i;
            // ab woah exception wali condition

            if (count > 1)
            {
                // ab single single digit karke dalna hain
                string cnt = to_string(count);
                for (char ch : cnt)
                {
                    chars[ansIndex++] = ch;
                }
            }

            // ab agle character pe jao
            i = j;
        }
        return ansIndex;
    }
}