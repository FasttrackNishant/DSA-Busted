#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr1 = {1,2,3,4};
    vector<int> arr2 = {2,4,7,8};
    int K = 8;

    for(int i = 0 ; i < arr1.size(); i++ )
    {
        for(int j = 0 ; j < arr2.size() ; j++)
        {
            if(arr1[i] + arr2[j] > K)
            {
                cout<<arr1[i]<<" , " << arr2[j]<<endl;
            }

        }

    }


    
    return 0;
}