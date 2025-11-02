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

    void print()
    {
        cout << "level is " << level << endl;
        cout << "health  is " << health << endl;
    }

    // constructor created
    hero()
    {
        cout << "Default constructor " << endl;
    }

    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    // copy constructor

    hero(hero &temp)
    {
        cout << "copy constructor called "<<endl;
        this->health = temp.health + 5;
        this->level = temp.level;
    }

    /*but yaha pe error kyu aa raha age meiny yahah
    & laga do to error hat jayega but hua kya actual amein */
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
    hero suresh(70, 'C');

    hero ritesh(suresh);
    ritesh.print();

    return 0;
}