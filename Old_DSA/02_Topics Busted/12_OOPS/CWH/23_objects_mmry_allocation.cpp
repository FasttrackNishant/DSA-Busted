#include <iostream>
using namespace std;

class shop
{

    int itemid[100];
    int itemprice[100];
    int counter;

public:
    void initcounter(void)
    {
        counter = 0;
    }

    void display(void);
    void setprice(void);
};

void shop ::setprice(void)
{
    cout << "Enter id of item " << counter + 1 << endl;
    cin >> itemid[counter];
    cout << "Enter price of item " << counter + 1 << endl;

    cin >> itemprice[counter];
    counter++;
}

void shop ::display(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item :- " 
        << itemprice[i] << "with id is : -" << itemid[i] << endl;
    }
}

int main()
{
    shop ramu;
    ramu.initcounter();
    ramu.setprice();
    ramu.setprice();
    ramu.setprice();
    ramu.display();

    return 0;
}