#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {

    map<string, int> m;

    // ways of insertion
    // 1
    pair<string,int> p = make_pair("jane",3);

    // 2
    pair<string,int> pair2("love",2);

    // 3
    // if not present new entry will be created
    m["new"] = 1;

    // Search

    cout<<m["new"] <<endl;

    // thorow exception
    // cout << m.at("notpresent");

    cout << m["zeroreturn"] << endl;

    map<string, int>::iterator it = m.begin();

    while(it != m.end())
    {
        cout<<it->first << "-" <<it->second<<endl;
        it++;
    }

    cout << endl;

    return 0;
}