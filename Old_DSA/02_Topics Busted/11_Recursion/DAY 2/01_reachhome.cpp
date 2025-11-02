#include <iostream>
using namespace std;

void reachome(int src, int dest)
{cout<<src <<" "<<endl;
    if (src == dest)
    {
        cout << "ghar aa gaye" << endl;
        return;
    }
    reachome(src + 1,dest);
}
int main()
{
    int dest = 20;
    int src = 1;
    cout << endl;
    reachome(src, dest);
    cout << endl;
    return 0;
}