class SpecialStack {
  public:
    
    stack<int> s;
    int mini = INT_MAX;
    
    SpecialStack() {
       
    }

    void push(int data) {
        
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini)
            {
                // Store encoded value: 2*data - mini
                s.push(2*data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
        
    }

    void pop() {
        if(s.empty())
        {
            return;
        }
       
        int curr = s.top();
        s.pop();  // Actually remove the element
       
        if(curr < mini)  // Current top was encoded
        {
            // Restore previous mini
            mini = 2*mini - curr;
        }
    }

    int peek() {
        if(s.empty())
        {
            return -1;
        }
        
        int curr = s.top();
        
        // If curr < mini, it means this was encoded
        // The actual value when pushed was mini
        if(curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int top() {  // Better name than peek() for consistency
        return peek();
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
        {
            return -1;
        }
        
        return mini;
    }
};