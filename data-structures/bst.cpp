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
    static void insert(Node *_root, int _data)
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
