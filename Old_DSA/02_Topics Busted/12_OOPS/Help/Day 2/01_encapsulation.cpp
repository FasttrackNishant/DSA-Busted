#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int age = 56;
    int height;

public:
    int getAge()
    {
        cout << "age is " << this->age << endl;
    }
};
int main()
{
    student first;
    first.getAge();

    cout << endl;
    return 0;
}