#include <bits/stdc++.h>
using namespace std;

void printpermutations(int index, vector<string> &output, string &str)
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
        // recursive call mardi
        printpermutations(index + 1, output, str);

        // backtrack kardiya
        swap(str[index], str[j]);
    }
}

int main()

{
    string str = "xyz";
    vector<string> output; // isme sare permutations store karenge
    int index = 0;
    printpermutations(index, output, str);

    cout << "Printing all permutations " << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}