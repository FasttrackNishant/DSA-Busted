#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> marks;

    // here create 10 size vector
    vector<int> miles(10);

    //create 15 size initialize with 0
    vector<int> dists(15,0);

    //methods in vector

    cout << "Start by the iterator " << *(dists.begin()) << endl;

    // push_back -> to insert at the end 
    marks.push_back(10);
    marks.push_back(30);
    marks.push_back(50);

    //check size
    cout<<"Size is "<<marks.size()<<endl;

    //pop_back() -> to remove the element from the vector

    //front -> first element of the vector
    cout<<"First"<<marks.front()<<endl;

    //back -> last element of the vector
    cout << "Last" << marks.back();

    //empty -> check vector size
    if(marks.empty())
    {
        cout<<"Empty hain "<<endl;
    }
    else
    {
        cout<<"Not empty"<<endl;
    }

    // then there is [] -> size honi chahiye nahi toh segmentation fault aa jayega
    cout<<"Using [] at 0 index"<<marks[0]<<endl;

    //at
    cout << "Usint at a 0 index" << marks.at(0) << endl;

    //capacity -> vector kitne element hold kar sakta hain at a time 
    cout<<"Capacity of marks"<<marks.capacity()<<endl;

    //reserve -> to change the capacity by reserving blocks
    marks.reserve(50);
    cout << "Capacity after reserving " << marks.capacity()<<endl;

    //max_size -> this is system capacity for the max vector size
    cout << "Max size of the vector" << marks.max_size()<<endl;

    cout<<"Size before erase"<<marks.size()<<endl;

    marks.erase(marks.begin(),marks.end());

    cout<<"After Erase "<<marks.size();

    


    return 0;
}