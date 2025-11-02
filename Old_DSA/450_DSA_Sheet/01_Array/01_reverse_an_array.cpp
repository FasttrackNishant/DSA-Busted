#include <bits/stdc++.h>
using namespace std;
void printarr(int arr[] , int size);
int reversearr( int arr[] , int position,int size )
{
    for (int i = position; i < size; i++)
 {
  if(arr[i]>= arr[4-i])
  {
     int temp = arr[i];
     arr[i]=arr[4 -i];
     arr[4 -i]=temp;
    //   cout<<arr[i]<<" ";
}
 }
 for (int i = 0; i <size; i++)
  {
      cout<<arr[i]<<" ";
  }
//   printarr(arr , size);


 }
void printarr(int arr[] , int size)
{
 for (int i = 0; i <size; i++)
  {
      cout<<arr[i]<<" ";
  }
 }

int main()
{
    int arr[]={10,20,30,40,50};
    int size = sizeof(arr)/4;
    int position ;
    cin>>position;
  
  reversearr( arr ,position, size);
  

    return 0;
}