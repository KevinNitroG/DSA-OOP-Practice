#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
};
