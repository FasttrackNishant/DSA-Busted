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
    static int timetocomplete;

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
        // ab jab ye copy constructor call hoga toh new array ban jayega jisme old array ki values copy ho jayengi
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "copy constructor called " << endl;
        this->health = temp.health + 5;
        this->level = temp.level;
    }

    static int random()
    {
        /*
        it can access only static memebers
        not health 
        not level
        not name*/

        cout<<"static member ";
        return timetocomplete;
    }
    ~hero()
    {
        cout << "destructor called";
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

int hero ::timetocomplete = 5;

int main()
{

    hero a;

    hero *b = new hero;

    delete b;

    // static data member
    cout << hero ::timetocomplete << endl;

//ye se na karo class se access karo 
    cout << a.timetocomplete << endl;

    //accessing via static functions 

 cout<<   hero:: random()<<endl;
    return 0;
}