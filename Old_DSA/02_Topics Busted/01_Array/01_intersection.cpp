#include <iostream>
using namespace std;

/* version -1
this is correct answer but TLE is there so chage the complexity 

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
vector <int> ans;
	for(int i=0 ; i< n; i++)
	{
		int element = arr1[i];
		
		for(int j =0; j< m ; j++)
		{
			if(element == arr2[j])
			{
				ans.push_back(element);
				arr2[j] = -1;
				break;
			}
		}
	}
	return ans;
}*/

/*
version -2

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
vector <int> ans;
	for(int i=0 ; i< n; i++)
	{
		int element = arr1[i];
		
		for(int j =0; j< m ; j++)
		{
        
        if(element < arr2[j])
        {
            break;
        }
			if(element == arr2[j])
			{
				ans.push_back(element);
				arr2[j] = -1;
				break;
			}
		}
	}
	return ans;

*/


/*
original code


*/
void intersection (int vec1, int vec2 )
{



}
int main()
{
    vector<int> vec;
    intersection(vec1,vec2);
    cout <<
    return 0;
}