#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head->next)
            return head;
        ListNode *current = head->next;
        head->next = nullptr;
        ListNode *temp = nullptr;
        ListNode *next = nullptr;
        while (current)
        {
            temp = head;
            next = current->next;
            current->next = nullptr;
            if (current->val < temp->val)
            {
                current->next = temp;
                head = current;
                current = next;
                continue;
            }
            while (temp->next && current->val > temp->next->val)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
            current = next;
        }
        return head;
    }
};
