//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    
    private :
    
    Node * getMid(Node * head)
    {
        Node * slow = head;
        Node * fast = head ->next;
        
        while (fast !=NULL && fast ->next !=NULL)
        {
             fast = fast ->next ->next ;
             slow = slow ->next;
             
        }
        
        return slow;
        
    }
    
    Node * reverse(Node * head)
    {
         Node * curr = head;
         Node *prev = NULL;
         Node *next = NULL;
         
         while (curr != NULL)
         {
              next = curr ->next ;
              curr ->next = prev;
              prev = curr;
              curr = next;
              
         }
         return prev;
    }
  public:
  
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       if(head ==NULL || head ->next ==NULL)
       return true;
    
    //step 1 find the mid
    
    Node * middle = getMid(head);
    
     //step 2 revese list after middle
     
     Node *temp = middle ->next;
     middle ->next = reverse(temp);
     
     //step 3 compare both halfves j
        Node * head1  = head;
        Node * head2 = middle ->next;
        
        while (head2 != NULL )
        {
            if(head1 ->data != head2 ->data)
            {
                return false;
            }
            head1 = head1 ->next;
            head2 = head2 ->next;
        }
       
           //ab agar loop se bahar aa gaye means palinndrome hain bas ab list ko pehle jaise bana deo
        
        //step4 -repeat step 2
          temp = middle ->next;
     middle ->next = reverse(temp);
     
        
        return true;
    
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends 