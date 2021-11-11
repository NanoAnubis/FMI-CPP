#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main() {


	int n;
	cin >> n;

	//vector<queue<int>> storage;
	vector<int> storage(2*n+1,-1);
	//storage.resize(2*n + 1);

	//storage[n].push(0);
	storage[n] = 0;

	vector<int>pos(n,-1);

	if (pos.size() > 0)pos[0] = n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x != -1) {
			pos[x] = pos[i] - 1;
			if (storage[pos[x]] == -1)storage[pos[x]] = x;
			//storage[pos[x]].push(x);
		}
		if (y != -1) {
			pos[y] = pos[i] + 1;
			if (storage[pos[y]] == -1)storage[pos[y]] = y;
			//storage[pos[y]].push(y);
		}
		
	}

	for (int i = 0; i < (int)storage.size(); i++) {
		//if(storage[i].size()>0) cout<<storage[i].front()<<" ";
		if (storage[i] != -1)cout << storage[i] << " ";
	}

    return 0;
}