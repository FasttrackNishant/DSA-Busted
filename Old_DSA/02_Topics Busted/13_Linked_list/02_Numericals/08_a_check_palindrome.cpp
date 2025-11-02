
#include <vector>
class Solution {
    
    private:
    
    bool checkpalindrome(vector <int> arr)
    {

     int n = arr.size();
        int s = 0;
        int e = n-1;
        
        
        while (s<=e)
        {
    
            if( arr[s]!=arr[e])
            {
                return 0;
            }
            s++;
            e--;
        }
        
        return 1;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        //step 1
        
        vector <int> arr;
        
        ListNode * temp = head;
        while (temp != NULL)
        {
 
        arr.pushback(temp->data);
            temp  = temp->next;
        }
        
        
        return checkpalindrome(arr);
        
    }
};