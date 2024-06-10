#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(const int &n)
{
    return new Node{n, NULL, NULL};
}

void AddNode(Node *&root, const int &n)
{
    if (!root)
        root = CreateNode(n);
    if (root->data > n)
        return AddNode(root->left, n);
    if (root->data < n)
        return AddNode(root->right, n);
}

void printNLR(Node *&root)
{
    if (!root)
        return;
    cout << root->data;
    printNLR(root->left);
    printNLR(root->right);
}

Node *DeleteNode(Node *&root, const int &n)
{
    // https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
    if (!root)
        return root;
    if (root->data > n)
        return DeleteNode(root->left, n);
    if (root->data < n)
        return DeleteNode(root->right, n);

    if (root->left == NULL)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    if (root->right == NULL)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }

    // Find rightly of left child
    Node *succ = root->left;
    Node *succPar = NULL;
    while (succ->right)
    {
        succPar = succ;
        succ = succ->right;
    }
    root->data = succ->data;
    if (succPar == root)
        succPar->left = succ->left;
    else
        succPar->right = succ->left;
    delete succ;
    return root;
}

int main()
{
    int n;
    int input;
    Node *root = NULL;

    cin >> n;

    while (n--)
    {
        cin >> input;
        AddNode(root, input);
    }

    cout << "Xuat cac node" << endl;
    printNLR(root);

    cout << "Nhap lan xoa: ";
    cin >> n;
    while (n--)
    {
        cin >> input;
        DeleteNode(root, input);
    }

    cout << "Xuat cac node" << endl;
    printNLR(root);

    return 0;
}
