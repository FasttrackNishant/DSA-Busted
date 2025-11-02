#include <iostream>
#include <string>
// Nesting of memeber functions
using namespace std;

class binary
{
    string s;

public:
    void read(void);
    void chk_bin(void);
    void ones(void);
    void display(void);
};

void binary ::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((s.at(i) != '0') && (s.at(i) != '1'))
        {
            cout << "Incorrect Binary Number" << endl;
            exit(0);
        }
    }
}

void binary ::ones(void)
{
    chk_bin(); //this is called as nesting of 
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
        else
        {
            s.at(i) = '1';
        }
    }
    display();
}

void binary ::display(void)
{
    cout << "Your Binary Number is " << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}
int main()
{
    binary b;

    b.read();
    b.ones();
    return 0;
}