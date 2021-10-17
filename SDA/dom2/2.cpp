#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<utility>
using namespace std;


bool compare(vector<int>& l,vector<int>& r) {
	
	if (l[5] < r[5]) {
		return true;
	}
	else if (l[5] == r[5]) {
		if (l[4] < r[4]) {
			return true;
		}
		else if (l[4] == r[4]) {
			if (l[3] < r[3]) {
				return true;
			}
			else if (l[3] == r[3]) {
				if (l[0] < r[0]) {
					return true;
				}
				else if (l[0] == r[0]) {
					if (l[1] < r[1]) {
						return true;
					}
					else if (l[1] == r[1]) {
						if (l[2] <= r[2]) {
							return true;
						}
					}
				}
			}
		}
	}
	
	return false;
	
}


void merge(vector<pair<vector<int>, long long>>& arr, int low, int mid, int high) {
	vector<pair<vector<int>, long long>> left;
	vector<pair<vector<int>, long long>> right;

	for (int i = low; i <= mid; i++) {
		left.push_back(arr[i]);
	}

	for (int i = mid + 1; i <= high; i++) {
		right.push_back(arr[i]);
	}

	unsigned int i = 0;
	unsigned int j = 0;

	int index = low;
	while (i < left.size() && j < right.size()) {
		if (compare(left[i].first, right[j].first)) {
			arr[index++] = left[i++];
		}
		else {
			arr[index++] = right[j++];
		}
	}

	while (i < left.size()) {
		arr[index++] = left[i++];
	}

	while (j < right.size()) {
		arr[index++] = right[j++];
	}
}

void merge_sort(vector<pair<vector<int>, long long>>& arr, int low, int high) {

	if (low < high) {
		int mid = (low + high) / 2;

		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);

		merge(arr, low, mid, high);
	}
}


int main() {

	long long n;
	cin >> n;

	vector<pair<vector<int>, long long>>output;
	for (long long i = 0; i < n; i++) {
		
		string tmp;
		stringstream ss;
		cin >> tmp;
		ss << tmp << " ";
		cin >> tmp;
		ss << tmp;

		string h;
		string m;
		string s;
		string dd;
		string mm;
		string yy;
		getline(ss, h, ':');
		getline(ss, m, ':');
		getline(ss, s, ' ');
		getline(ss, dd, '.');
		getline(ss, mm, '.');
		getline(ss, yy);

		vector<int> tmp1;
		tmp1.push_back(stoi(h)); //0
		tmp1.push_back(stoi(m)); //1
		tmp1.push_back(stoi(s)); //2
		tmp1.push_back(stoi(dd));//3
		tmp1.push_back(stoi(mm));//4
		tmp1.push_back(stoi(yy));//5

		pair<vector<int>, long long> tmp2{ tmp1,i + 1 };
		output.emplace_back(tmp2);

	}


	merge_sort(output, 0, output.size() - 1);

	for (unsigned long i = 0; i < output.size(); i++) {
		cout << output[i].second << endl;
	}

	return 0;
}