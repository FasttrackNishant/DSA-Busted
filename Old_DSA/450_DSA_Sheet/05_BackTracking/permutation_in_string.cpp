#include <bits/stdc++.h>
using namespace std;
// =

void printAllPermutations(int index, vector<string> &output, string &str)
{
    // base case
    if (index == str.length())
    {
        output.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        printAllPermutations(index + 1, output, str);

        // back track
        swap(str[index], str[j]);
    }
}

int main()
{
    string str = "xyzx";
    vector<string> output;
    int index = 0;
    printAllPermutations(index, output, str);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " " << endl;
    }
    cout << endl;

    return 0;
}