#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Tree {
private:

    struct Node {

        int val;

        Node* left;
        Node* right;

        Node(int v): val(v) {
            left = nullptr;
            right = nullptr;
        }
    };

    Node* add_p(Node* root, int v) {
        if (root == nullptr) {
            return new Node(v);
        }

        if (v < root->val) {
            root->left = add_p(root->left, v);
        }
        else if (v > root->val) {
            root->right = add_p(root->right, v);
        }
        return root;
    }

    Node* remove_p(Node* root, int v) {
        if (root == nullptr) {
            return root;
        }

        if (v < root->val) {
            root->left = remove_p(root->left, v);
        }
        else if (v > root->val) {
            root->right = remove_p(root->right, v);
        }
        else if (v == root->val) {
            if (root->left == nullptr) {
                Node* tmp = root->right;
                delete root;

                output.erase(find(output.begin(), output.end(), v));
                return tmp;
            }
            else if (root->right == nullptr) {
                Node* tmp = root->left;
                delete root;

                output.erase(find(output.begin(), output.end(), v));

                return tmp;
            }
            else {
                Node* tmp = root->right;
                while (tmp->left != nullptr) {
                    tmp = tmp->left;
                }

                root->val = tmp->val;

                //root->right = remove_p(root->right, tmp->val);

                output.erase(find(output.begin(), output.end(), tmp->val));
                for (int i = 0; i < output.size(); i++) {
                    if (output[i] == v) {
                        output[i] = tmp->val;
                        break;
                    }
                }
            }
            return root;
        }
        return nullptr;
    }

    /*int find_height(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(find_height(root->left), find_height(root->right)) + 1;
    }

    void fill_values_height(Node* root, int h) {

        if (root == nullptr) {
            return;
        }

        values_height[h].push_back(root->val);

        fill_values_height(root->left, h + 1);
        fill_values_height(root->right, h + 1);
    }*/


public:

    Node* root;

    Tree() : root(nullptr) {}

    vector<int> values;
    //vector<vector<int>> values_height;

    vector<int> output;

    void add(int v) {
        root = add_p(root, v);
        values.push_back(v);
    }

    void remove(int v,int k) {
        remove_p(root, v);
        //values.erase(values.begin() + k);
        //values.shrink_to_fit();
    }

    /*void print() {

        int h = find_height(root);
        values_height.resize(h);

        fill_values_height(root,0);

        for (vector<int> height : values_height) {
            for (int p : height) {
                cout << p << " ";
            }
        }
    }*/

};



int main() {

    int n, k;
    cin >> n >> k;

    Tree tree;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        tree.add(tmp);
    }

    tree.output = tree.values;

    sort(tree.values.begin(), tree.values.end(), greater<int>());

    tree.remove(tree.values[k-1],k-1);

    //tree.print();
    for (int i : tree.output) {
        cout << i << " ";
    }

    return 0;
}