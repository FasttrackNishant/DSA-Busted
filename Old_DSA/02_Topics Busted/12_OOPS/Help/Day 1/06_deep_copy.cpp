#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class hero
{
    int health;

public:
    char *name;
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
        cout << endl;

        cout << "{ Name : " << this->name << ",";
        cout << " level : " << level << ",";
        cout << "health : " << health << "}" << endl;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    // constructor created
    hero()
    {
        cout << "Default constructor called  " << endl;
        name = new char[100]; // dynamically created
    }

    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    // copy constructor

    hero(hero &temp)
    { // +1 null char ke liye
    //ab jab ye copy constructor call hoga toh new array ban jayega jisme old array ki values copy ho jayengi  
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;

        cout << "copy constructor called " << endl;
        this->health = temp.health + 5;
        this->level = temp.level;
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

    hero hero1;
    hero1.sethealth(12);
    hero1.setlevel('D');

    char name[8] = "codying";
    hero1.setName(name);
    hero1.print();

    // default copy constructor

    hero hero2(hero1);
    cout << endl
         << endl;
    hero2.print();

    // operation on hero

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();

    // ab deep copy karte hain so chage kiya at line 55  and ab result sahi se dikhega 

    return 0;
}