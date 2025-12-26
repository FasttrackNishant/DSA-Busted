/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getTotalNodes(Node * root)
    {
        if(!root) return 0;
        
        return 1 + getTotalNodes(root->left) + getTotalNodes(root->right);
    }
    
    bool isCBT(Node * root, int total , int index)
    {
        if(!root) return true;
        
        // cout<<index<<endl;
        if(index >= total)
            return false;
            
        return isCBT(root->left , total , 2 * index + 1 )
        && isCBT(root->right,total , 2 * index + 2);
     
    }
    
    bool isHeapOrder(Node * root)
    {
        if(!root) return true;
        
        if(!root->left && !root->right)
            return true;
            
        if(!root->right)
            return root->data > root->left->data;
            
        if(root->left && root->right)
            return root->data > root->left->data &&
                root->data > root->right->data &&
                isHeapOrder(root->left) && isHeapOrder(root->right);
                
        return false;
                
    }
    
    
    bool isHeap(Node* root) {
        
        if(!root) return true;
        
        int totalNode = getTotalNodes(root);
        
        return isCBT(root,totalNode , 0 ) && isHeapOrder(root);
        
    }
};