#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node* root;

    Node* insert(Node* root, int value)
    {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);
        else
            cout << "Duplicate value not inserted\n";

        return root;
    }

public:
    BST()
    {
        root = NULL;
    }

    void read()
    {
        int n, value;

        cout << "Enter number of nodes: ";
        cin >> n;

        cout << "Enter node values: ";
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            root = insert(root, value);
        }
    }

    void inorder()
    {
        stack<Node*> st;
        Node* current = root;

        cout << "Inorder Traversal: ";

        while (current != NULL || !st.empty())
        {
            while (current != NULL)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            cout << current->data << " ";
            current = current->right;
        }

        cout << endl;
    }

    void preorder()
    {
        if (root == NULL)
            return;

        stack<Node*> st;
        st.push(root);

        cout << "Non-Recursive Preorder Traversal: ";

        while (!st.empty())
        {
            Node* current = st.top();
            st.pop();

            cout << current->data << " ";

            if (current->right != NULL)
                st.push(current->right);

            if (current->left != NULL)
                st.push(current->left);
        }

        cout << endl;
    }
};

int main()
{
    BST tree;
    tree.read();
    tree.inorder();
    tree.preorder();

    return 0;
}