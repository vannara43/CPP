#include <iostream>
#include <queue>
using namespace std;

// Node structure
class AVLNode
{
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int value)
    {
        key = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// AVL Tree class
class AVLTree
{
public:
    AVLNode *insert(AVLNode *root, int key)
    {
        // Perform the normal BST insertion
        if (!root)
            return new AVLNode(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);

        // Update the height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Balance the node
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && key > root->left->key)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->key)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode *deleteNode(AVLNode *root, int key)
    {
        // Perform standard BST delete
        if (!root)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            // Node with one child or no child
            if (!root->left || !root->right)
            {
                AVLNode *temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                // Node with two children
                AVLNode *temp = getMinValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root)
            return root;

        // Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Balance the node
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preorder(AVLNode *root)
    {
        if (root)
        {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(AVLNode *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void postorder(AVLNode *root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }

    void levelOrder(AVLNode *root)
    {
        if (!root)
            return;
        queue<AVLNode *> q;
        q.push(root);
        while (!q.empty())
        {
            AVLNode *current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

private:
    int getHeight(AVLNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode *getMinValueNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current->left)
            current = current->left;
        return current;
    }
};

// Main function to demonstrate AVL Tree
int main()
{
    AVLTree tree;
    AVLNode *root = nullptr;

    // Insert nodes
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    cout << "Preorder traversal after insertions:\n";
    tree.preorder(root);
    cout << endl;

    // Delete a node
    root = tree.deleteNode(root, 30);
    cout << "Preorder traversal after deletion:\n";
    tree.preorder(root);
    cout << endl;

    cout << "Inorder traversal:\n";
    tree.inorder(root);
    cout << endl;

    cout << "Postorder traversal:\n";
    tree.postorder(root);
    cout << endl;

    cout << "Level-order traversal:\n";
    tree.levelOrder(root);
    cout << endl;

    return 0;
}
