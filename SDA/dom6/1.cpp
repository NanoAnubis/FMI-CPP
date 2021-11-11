#include<iostream>
#include<vector>

using namespace std;


class tree {

private:

	struct Node
	{
		int val;
		vector<Node*> links;

		Node(int val) :val(val) {}
	};


public:
	
	Node* root;
	vector<Node*> positions;

	tree() {
		Node* first = new Node(0);
		positions.push_back(first);
		root = first;
	}

	~tree() {
		for (Node* i : positions) {
			delete i;
		}
	}


	void add(int pos, int num) {

		Node* tmp = new Node(0);
		positions[pos]->links.push_back(tmp);
		if (positions.size() <= num) positions.resize(num + 1);
		positions[num] = tmp;
	}

	int calculate(Node* curr) {

		if (curr->links.size() == 0) {
			curr->val = 0;
			return 0;
		}

		for (int i = 0; i < curr->links.size(); i++) {
			curr->val += calculate(curr->links[i]) + 1;
		}

		return curr->val;
	}


};



int main() {
    
	tree company;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		company.add(x, y);
	}

	company.calculate(company.root);

	for (int i = 0; i < company.positions.size(); i++) {
		cout<<company.positions[i]->val<<" ";
	}

    return 0;
}