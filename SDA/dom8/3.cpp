#include<iostream>
#include<set>
#include<vector>
#include<utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    multiset<pair<int, int>> students;
    int time = 0;

    for (int i = 1; i <= n; i++) {
        int s, l;
        cin >> s >> l;
        pair<int, int> tmp{ l,s };
        students.insert(tmp);
    }

    int med = 0;

    auto curr = students.begin();
    multiset<int>min_starts;

    while (!students.empty()) {
        if ((*curr).second <= time) {
            med += (time + (*curr).first - (*curr).second);
            time += (*curr).first;
            students.erase(curr);
            curr = students.begin();
            min_starts.clear();
        }
        else {
            min_starts.insert((*curr).second);
            curr++;
        }
        if (curr == students.end() && min_starts.size()!=0) {
            curr = students.begin();
            time = *min_starts.begin();
            min_starts.clear();
        }
    }

    med /= n;
    cout << med;

    return 0;
}


/*
10
2 5
6 7
6 8
22 1
51 8
9 9
6 1
3 97
31 2
11 21
*/