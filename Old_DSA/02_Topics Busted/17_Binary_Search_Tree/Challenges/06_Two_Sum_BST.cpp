#include <bits/stdc++.h> 
// Following is the Binary Tree node structure

class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode<int>* root, vector<int> &in)
{

    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector <int> inorderVal;

//store inorder to sorted values

    inorder(root, inordeVal);
    int i = 0;
    int j = inorderVal.size() - 1;

    //used two pointer approach to check if pair exis or not

    while (i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{

}