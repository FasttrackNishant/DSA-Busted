class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        
        queue<int> q1;

        
        int size = q.size();
        
        for(int i = 0 ; i < size/2 ; i++)
        {
            q1.push(q.front());
            q.pop();
        }
        
        while(!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
            
            q.push(q.front());
            q.pop();
        }
    
    }
};

// stack
first hald push in stack
push stack in queue
push first hald in queue
push first hald in stakc
push stack one and fir helf one in the queue