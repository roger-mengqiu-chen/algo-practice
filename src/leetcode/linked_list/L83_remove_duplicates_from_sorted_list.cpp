#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *n;
        ListNode *h = head;
        while(h != NULL)
        {
            n = h->next;
            while(n != NULL && n->val == h->val)
            {
                n = n->next;
            }
            h->next = n;
            h = n;
        }
        return head;
    }   

    // The solution below is from leetcode and only uses 1 pointer
    ListNode* deleteDuplicates2(ListNode* head)
    {
        ListNode* curr = head;
        while(curr)
        {
            while (curr->next && curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    ListNode l(2);
    ListNode l2(1, &l);
    ListNode l3(1, &l2);
    // ListNode l4(1, &l3);
    // ListNode l5(1, &l4);

    for(ListNode *p = &l3; p != 0; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << endl;

    Solution s;
    s.deleteDuplicates(&l3);

    for(ListNode *p = &l3; p != 0; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}