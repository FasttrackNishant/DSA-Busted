#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left ;
        Node * right ; 

    Node(){}

    Node(int d)
    {
        this->left = NULL;
        this-> right = NULL ;
        this->data = d;
    }
};

/*
### Approach 1 :

- Longest length between any two nodes
- ab yaha pe ending node leaf bhi ho skti hain ya , root bhi ho skati hain
- 3 possibilities hain
    - left mein hoga
    - right mein hoga
    - left + right ki heigfht + 1
        - ismein jo max woh answer
- yaha issue eisa hain ki
    - height ke liye ek bar ja raha
        - o(n)
    - diameter ke liye
        - O ⇒ n
- do no milkae
    - O ⇒ n ^ 2
*/
int diameterOfBinaryTree(Node * root)
{
    if(root==NULL) return 0;

    // 3 choice

    //left
    int op1 = diameterOfBinaryTree(root->left);

    //right
    int op2 =  diameterOfBinaryTree(root->right);

    //left || right ki height + 1
    int op3 = max(height(root->left) , height(root->right) ) + 1;

    return op3;

}


/*
### Diameter Fast Approach

pair<int, int> 
    first position mein -> diameter
    second position mein -> height

*/

pair<int, int> diameterFast(Node *root)
{
    if(root== NULL) 
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    //left
    pair <int,int> leftAns = diameterFast(root->left);

    //right
    pair<int,int> rightAns = diameterFast(root->right);


    int op1 = leftAns.first;
    int op2 = rightAns.first;
    int op3 = leftAns.second + rightAns.second + 1;
    
    //diameter ans
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));

    //height    
    ans.second = max(leftAns.second, rightAns.second) + 1;

    // dono ki height + 1

    return ans;


}

int main() {
    Node * root = new Node();
    return diameterFast(root).first;
    cout << "Hello World" << endl;

    return 0;
}