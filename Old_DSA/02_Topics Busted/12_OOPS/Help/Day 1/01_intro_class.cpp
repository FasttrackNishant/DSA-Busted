#include <iostream>
// #include "00_link.cpp"
using namespace std;

/* class Hero
 {

    // public :
    // int health;


    in case of int health prsent 4 will be therrer
    but if the class is empty then 1 byte is allocated by the system
 };

*/

class Hero
{
    int health;

public:
    char level;

    // default constructor

    Hero()
    {

        cout << "Constructor here" << endl;
    }

    void print()
    {
        cout << "level is " << level << endl;
    }
    // Getter
    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
};

int main()
{

    /*
        // static allocation
        Hero a;
        a.setHealth(50);
        cout << a.getHealth() << endl;
        a.setLevel('B');
        cout << a.getLevel() << endl;

        // dynamic allocation
        Hero *b = new Hero;
        (*b).setHealth(100);
        cout << (*b).getHealth()<<endl;
        //one more way
        b->setLevel('C');
        cout << b->getLevel();

        //     Hero h1;
        //     /*   h1.health = 80;
        //        h1.level = 'z';
        //        cout << h1.health << endl;
        //        cout << h1.level << endl;
        //
        //     h1.setHealth(95);
        //     h1.setLevel('v');
        //     cout << "Size of Ramesh " << sizeof(h1) << endl;
        //     cout << h1.getHealth() << endl;
        //     cout << h1.getLevel();

        //     // cout<<"size of h1 "<<s izeof(h1)<<endl;


    */

    // object created to test constructor
    //  ye object banane se hi contructor called ho gaya
    Hero ramesh;

    // dynamically

    Hero *h = new Hero;
    // iske liye bhi contructor called hota hain

    return 0;
}