#include <iostream>
using namespace std;

// convert a bst to linked list
// merge 2 sorted linked list
// sorted linked list

void convertintoSortedDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    // base case
    if (root == NULL)
        return NULL;

    convertintoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
    {

        head->left = root;
    }

    head = root;

    convertintoSortedDLL(root->left, head);
}

TreeNode<int> *mergeLinkedlist(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;

                // woh chhota hain to gaya
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head1 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head1->right;
            }
        }
    }

    while (head1 != NULL)

    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head1->right;
    }
}

// AB linked list se bst banana hain

// to calculate number of nodes

int countNodes(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL)

    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
TreeNode<int> *sortedLLToBST(TreeNode<int> *&head, int n)
{
    // base case

    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode<int> *left = sortedLLToBST(head, n / 2);
    TreeNode<int> *root = head;

    root->left = left;
    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{

    // step 1;
    TreeNode<int> *head1 = NULL;
    convertintoSortedDLL(root1, head1);
    head1->left = NULL;
    TreeNode<int> *head2 = NULL;
    convertintoSortedDLL(root2, head1);
    head2->left = NULL;

    // step2 merge sorted linkedlist

    TreeNode<int> *head = mergeLinkedlist(head1, head2);

    // step 3 convert into bst

    return sortedLLToBST(head, countNodes(head));
}