/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Compare
{
    public:
    bool operator()(ListNode * a, ListNode * b)
    {
        return a-> val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int size = lists.size();
        priority_queue<ListNode* , vector<ListNode*> , Compare> pq;

        if(size == 0 )
            return nullptr;

        for(auto head : lists)
        {
               if(head != nullptr) {
                pq.push(head);
            }
        }

        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        while(!pq.empty())
        {
            ListNode * top = pq.top();
            pq.pop();

            if(top->next)
                pq.push(top->next);

            if(head == nullptr)
            {
                head = top ;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = tail->next;
            }

        }
        


        return head;
        
    }
};