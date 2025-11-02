#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVectorFun(const vector<T> & v)
{
    for(auto x : v) cout<< x<<" ";
    cout<<endl;
}