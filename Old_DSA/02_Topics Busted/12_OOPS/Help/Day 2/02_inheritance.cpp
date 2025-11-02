#include <iostream>
using namespace std;

class human
{

public:
    int height;
    int weight;

    int age;

public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : private human
{
public:
    string color;

    void sleep()
    {
        cout << "M sleeping " << endl;
    }
    int setheight()
    { 
        return this->height;
    }
};

int main()
{

    Male m1;
    cout<<m1.setheight()<<endl;
/*
    Male object1;
    cout << object1.age << endl;
    cout << object1.getAge() << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;

    object1.setWeight(58);
    cout << object1.weight << endl;
    object1.sleep();
*/
    return 0;
}