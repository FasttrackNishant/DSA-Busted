// User function Template for C++

class Solution {
  public:
  
    void heapify(vector<int> & arr , int n ,  int index)
    {
        int largest = index;
        int left = 2 * index  + 1;
        int right= 2 * index + 2;
        
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
            
        if(right < n && arr[right] > arr[largest])
            largest = right;
            
            
        if(largest != index)
            {
                swap(arr[index],arr[largest]);
                heapify(arr, n ,largest);
            }
        
        
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        for(auto it : b)
        {
            a.push_back(it);
            
        }
        
        int size = m + n;
      
        for(int i = size/2-1 ; i >= 0 ; i--)
        {
            heapify(a,size,i);
        }
        
        return a;
    }
};