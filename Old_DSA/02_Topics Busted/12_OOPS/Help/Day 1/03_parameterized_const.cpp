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
        cout<<"level is "<<level <<endl; 
    }

    // constructor created
    hero()
    {
        cout << "this is constructor " << endl;
    }

    // parameterized constructor

    hero(int health)
    {
        cout << "value of this ->" << this << endl;
        this->health = health;
    }

    hero(int health, char level)
    {
        cout << "value of this ->" << this << endl;
        this->level = level;
        this->health = health;
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
    // hero *h2 = new hero;
    // h2->sethealth(4);
    // (*h2).gethealth();

    // ------
    hero ramesh(10);
    // cout << "adress of ramesh " << &ramesh << endl;

    // dynamic way this
    hero *rameshd = new hero(18);
    // cout<<"adrsss of rameshd "<<&rameshd <<endl;

    // new const
    hero twopara(45, 'x');
twopara.print();
    return 0;
}