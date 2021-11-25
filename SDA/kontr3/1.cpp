#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    int sum = 0;


    int find_odd(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->leftNode == nullptr && root->rightNode == nullptr) {
            if (root->data % 2 != 0) {
                sum+=root->data;
                return 0;
            }
            else return 0;
        }
        find_odd(root->leftNode);
        find_odd(root->rightNode);

        return sum;
    }

    void leaves(Node* root) {
        find_odd(root);
        cout << sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}