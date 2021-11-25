#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }
    void insert(int value) {
        root = insert(root, value);
    }

    void printSpecific(int dividedBy) {
        num = dividedBy;
        /*if (root->value % num == 0) {
            cout << root->value << " ";
        }

        search(root->left);
        search(root->right);*/
        search(root);

        // TODO implement this function
    }

private:
    // you can implemented helper functions if you want

    void search(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        if (root->left != nullptr && root->right != nullptr) {
            if (root->value % num == 0) {
                cout << root->value << " ";
            }
        }

        search(root->left);
        search(root->right);
    }

    Node* root;
    int num;

    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};
int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    int dividedBy;
    cin >> dividedBy;
    tree.printSpecific(dividedBy);
    return 0;
}