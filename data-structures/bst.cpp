#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
  public:
    Node *root;
    static void insert(Node *&_root, int _data)
    {
        if (!_root)
        {
            _root = new Node{_data};
            return;
        }
        if (_root->data < _data)
            insert(_root->left, _data);
        else
            insert(_root->right, _data);
    }

    static void NLR(Node *_root)
    {
        if (!_root)
            return;
        cout << _root->data << " ";
        NLR(_root->left);
        NLR(_root->right);
    }

    static void printLevelK(Node *_root, int k)
    {
        if (!_root)
            return;
        if (!k)
            cout << _root->data << " ";
        else
        {
            printLevelK(_root->left, k - 1);
            printLevelK(_root->right, k - 1);
        }
    }

    static void removeMin(Node *&_root)
    {
        // In case delete the root node
        if (!_root)
            return;
        Node *cur = _root;
        while (cur->left)
            cur = cur->left;
        Node *temp = cur;
        cur = cur->right;
        delete temp;
        temp = NULL;
        // If the node deleted is root, update the root
        if (!_root)
            _root = cur;
    }

    static int findMax(Node *_root)
    {
        if (!_root)
            return -1;
        while (_root->right)
            _root = _root->right;
        return _root->data;
    }
};

int main()
{
    int n;
    cin >> n;
    BST tree;
    int data;
    while (n--)
    {
        cin >> data;
        tree.insert(tree.root, data);
    }
    tree.NLR(tree.root);
    return 0;
}
