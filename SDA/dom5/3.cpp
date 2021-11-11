#include<iostream>
//#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



int main() {

    long long n, d;
    cin >> n >> d;

    queue<long long> elements;
    deque<long long> min;

    long long sum = 0;

    for (long long i = 1; i <= d; i++) {
        long long tmp;
        cin >> tmp;

        elements.push(tmp);
        while (min.size() > 0 && min.back() > tmp) {
            min.pop_back();
        }
        min.push_back(tmp);
    }

    if(min.size()>0) sum += min.front();

    for (long long i = 1; i <= n-d; i++) {
        long long tmp;
        cin >> tmp;

        if (elements.front() == min.front()) {
            min.pop_front();
        }
        elements.pop();

        elements.push(tmp);
        while (min.size() > 0 && min.back() > tmp) {
            min.pop_back();
        }
        min.push_back(tmp);

        if (min.size() > 0)sum += min.front();
    }

    cout << sum;

    return 0;
}
