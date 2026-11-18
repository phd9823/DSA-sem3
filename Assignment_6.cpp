#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        } else {
            cout << "Duplicate Employee ID\n";
        }
        return node;
    }

    void levelOrder(Node* node) {
        if (node == NULL) {
            cout << "Tree is Empty\n";
            return;
        }
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        cout << endl;
    }

    Node* copyTree(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node* newNode = new Node();
        newNode->data = node->data;
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    int height(Node* node) {
        if (node == NULL) {
            return -1;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    void printLeafNodes(Node* node) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            cout << node->data << " ";
            return;
        }
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void displayLevelOrder() {
        levelOrder(root);
    }

    Node* copy() {
        return copyTree(root);
    }

    void displayCopiedLevelOrder(Node* copyRoot) {
        levelOrder(copyRoot);
    }

    int findHeight() {
        return height(root);
    }

    void displayLeafNodes() {
        printLeafNodes(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    Node* copiedRoot = NULL;
    int choice, n, value;

    do {
        cout << "\n=================================\n";
        cout << " Employee Database Analysis using BST\n";
        cout << "=================================\n";
        cout << "1. Insert Employee IDs\n";
        cout << "2. Display Original BST (Level Order)\n";
        cout << "3. Copy BST\n";
        cout << "4. Display Copied BST (Level Order)\n";
        cout << "5. Find Height of BST\n";
        cout << "6. Display Leaf Nodes\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of employee IDs: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter Employee ID: ";
                    cin >> value;
                    bst.insert(value);
                }
                break;
            case 2:
                cout << "Original BST (Level Order): ";
                bst.displayLevelOrder();
                break;
            case 3:
                copiedRoot = bst.copy();
                cout << "BST Copied Successfully.\n";
                break;
            case 4:
                cout << "Copied BST (Level Order): ";
                bst.displayCopiedLevelOrder(copiedRoot);
                break;
            case 5:
                cout << "Height of BST = " << bst.findHeight() << "\n";
                break;
            case 6:
                cout << "Leaf Nodes: ";
                bst.displayLeafNodes();
                break;
            case 7:
                cout << "Program Terminated.\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 7);

    return 0;
}