#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



void battle(stack<int>& to_right, queue<int>& to_left, vector<int>& output) {

    while (to_right.size() != 0 && to_left.size() != 0) {

        if (to_right.top() > to_left.front()) {
            to_left.pop();
        }
        else if (to_right.top() < to_left.front()) {
            to_right.pop();
        }
        else {
            to_left.pop();
            to_right.pop();
        }
    }

    /*int counter = 0;
    while (to_right.size() != 0) {
        counter++;
        output.push_back(to_right.top());
        to_right.pop();
    }
    if (counter != 0) {
        reverse(output.end() - counter, output.end());
    }*/

    while (to_left.size() != 0) {
        output.push_back(-to_left.front());
        to_left.pop();
    }

}


int main() {

    int n;
    cin >> n;
    stack<int>to_right;
    queue<int>to_left;
    vector<int>output;

    bool to_battle = false;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp > 0) {
            if (to_battle) {
                battle(to_right, to_left, output);
                to_battle = false;
            }
            to_right.push(tmp);

        }
        else if (tmp < 0) {
            to_left.push(-tmp);
            to_battle = true;
        }
    }

    battle(to_right, to_left, output);

    int counter = 0;

    while (to_right.size() != 0) {
        counter++;
        output.push_back(to_right.top());
        to_right.pop();
    }
    if (counter != 0) {
        reverse(output.end() - counter, output.end());
    }

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    if (output.size() == 0) {
        cout << '\n';
    }

    return 0;
}
