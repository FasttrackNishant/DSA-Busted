#include <iostream>
using namespace std;

int main() {
    cout<<"Hello world"<<endl;
    int t ;
    string s;
    cin>>t;
     cin.ignore();
    getline(cin,s);

    cout<<"no"<<t<<endl;
    cout<<"str"<<s<<endl;
    return 0;
}