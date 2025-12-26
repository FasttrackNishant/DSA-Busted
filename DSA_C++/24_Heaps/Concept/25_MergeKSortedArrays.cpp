class Node
{
    public:
    
    int data;
    int i ; 
    int j ;
    
    Node(int data ,int i , int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
        
    }
};

class Compare
{public:
    bool operator()(Node * a , Node * b)
    {
        return a->data > b->data;
    }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
       
       priority_queue<Node* , vector<Node*> , Compare > pq;
       vector<int> ans;
       
       int m = mat.size();
       
       for(int i = 0 ; i < m ;i++)
       {
           Node* data = new Node(mat[i][0],i,0);
           pq.push(data);
       }
       
       while(!pq.empty())
       {
           Node * top = pq.top();
           pq.pop();
           
           ans.push_back(top->data);
           
           if(top-> j + 1 < mat[top->i].size())
           {
               Node* newData = new Node(mat[top->i][top->j+1],top->i,top->j+1);
               pq.push(newData);
           }
           
           delete top;
           
       }
       
       return ans;
       
       
    }
};