
#include <iostream>
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

class BinaryTree
{
private:
    Node* root;

    Node* createTree()
    {
        int value;

        cout << "Enter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
        {
            return NULL;
        }

        Node* newNode = new Node(value);

        cout << "Enter left child of " << value << endl;
        newNode->left = createTree();

        cout << "Enter right child of " << value << endl;
        newNode->right = createTree();

        return newNode;
    }

    void inorder(Node* node)
    {
        if (node == NULL)
        {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node)
    {
        if (node == NULL)
        {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    void buildTree()
    {
        cout << "\nCreate Binary Tree\n";
        root = createTree();
        cout << "Binary Tree created successfully!\n";
    }

    void inorderDisplay()
    {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorderDisplay()
    {
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorderDisplay()
    {
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    int choice;

    tree.buildTree();

    do
    {
        cout << "\n===== BINARY TREE MENU =====\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.inorderDisplay();
            break;

        case 2:
            tree.preorderDisplay();
            break;

        case 3:
            tree.postorderDisplay();
            break;

        case 4:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
