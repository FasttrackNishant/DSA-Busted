#include <iostream>
using namespace std;

class hero
{
    int health;

public:
    char level;

    void sethealth(int h);
    void setlevel(char h);

    void gethealth(void)
    {
        cout << "the health is " << health << endl;
    }
    void getlevel(void)
    {
        cout << "the level is " << level << endl;
    }

    hero()
    {
        cout << "this is constructor" << endl;
    }
};

void hero ::sethealth(int h)
{
    health = h;
}

void hero::setlevel(char h)
{
    level = h;
}

int main()
{
    hero h1;
    h1.sethealth(4);
    h1.setlevel('t');
    h1.gethealth();
    h1.getlevel();

    return 0;
}