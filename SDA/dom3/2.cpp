#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


long long find_diff(const long long& team,const vector<long long>& tasks) {
	long long prev = 0, next = 0;

	if (team > tasks[tasks.size() - 1]) {
		return tasks[tasks.size() - 1];
	}
	else  if (team < tasks[0]) {
		return tasks[0];
	}


	long long left = 0;
	long long right = tasks.size() - 1;

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (team == tasks[mid]) {
			return tasks[mid];
		}
		if (tasks[mid] < team) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	prev = tasks[left];
	next = tasks[right];

	if (team - next > prev - team) {
		return prev;
	}
	else {
		return next;
	}
}


int main() {

	long long n, m;
	cin >> n >> m;
	vector<long long> tasks;
	vector<long long> teams;


	for (long long i = 1; i <= n; i++) {
		long long tmp;
		cin >> tmp;
		tasks.push_back(tmp);
	}

	sort(tasks.begin(),tasks.end());

	for (long long i = 1; i <= m; i++) {
		long long tmp;
		cin >> tmp;
		teams.push_back(find_diff(tmp,tasks));
	}

	for (long i = 0; i < m; i++) {
		cout << teams[i] << endl;
	}
	return 0;
}