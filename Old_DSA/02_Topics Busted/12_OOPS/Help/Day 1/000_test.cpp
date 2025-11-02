#include <iostream>
using namespace std;

class hero
{

public:
    int health;
    char level;

    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(char c)
    {
        level = c;
    }
    void getter()
    {
        cout << "Health is : " << health << endl;
        cout << "level is  : " << level << endl;
    }

    hero()
    {

        cout << "constructor called" << endl;
    }
    hero(int health)
    {
        health = health;
    }
};

int main()
{
    hero h1;
    h1.sethealth(33);
    h1.setlevel('f');
    h1.getter();

    hero *h2 = new hero;
    (*h2).sethealth(90);
    h2->setlevel('c');
    (*h2).getter();

    hero player(25);
    player.getter();

    hero *dymic = new hero;

    return 0;
}