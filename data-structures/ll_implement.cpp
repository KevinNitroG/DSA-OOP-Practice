#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
    Node *head;

  public:
    List() : head(NULL)
    {
    }
    Node *createNode(int _data)
    {
        return new Node{_data};
    }
    void pushBack(int _data)
    {
        if (this->head == NULL)
        {
            this->head = createNode(_data);
            return;
        }
        Node *temp = this->head;
        while (temp->next)
            temp = temp->next;
        temp->next = createNode(_data);
    }
    void print()
    {
        Node *temp = this->head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverse()
    {
        if (!this->head)
            return;
        Node *pre = NULL;
        Node *cur = this->head;
        Node *nex = this->head->next;
        while (nex)
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
            cur->next = pre;
        }
        this->head = cur;
    }

    void oddEven()
    {
        // this suck
        if (!this->head)
            return;
        Node *odd = this->head;
        Node *firstEven = this->head->next;
        Node *even = this->head->next;
        while (even)
        {
            if (even->next)
                odd = odd->next = even->next;
            if (odd->next)
                even = even->next = odd->next;
        }
        odd->next = firstEven;
    }
};

int main()
{
    int n;
    List list;
    int ele;
    cin >> n;
    while (n--)
    {
        cin >> ele;
        list.pushBack(ele);
    }
    list.reverse();
    list.oddEven();
    list.print();
    return 0;
}
