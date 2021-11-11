#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



int main() {

    vector<int> lections(62,-1);

    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        char tmp = input[i];
        int pos;
        if (tmp >= '0' && tmp<='9') {
            pos = tmp - 48;
            if (lections[pos] == -1) {
                lections[pos] = i;
            }
            else {
                lections[pos] = -2;
            }
        }
        else if(tmp >= 'A' && tmp <= 'Z') {
            pos = tmp - 55;
            if (lections[pos] == -1) {
                lections[pos] = i;
            }
            else {
                lections[pos] = -2;
            }
        }
        else if(tmp >= 'a' && tmp <= 'z') {
            pos = tmp - 61;
            if (lections[pos] == -1) {
                lections[pos] = i;
            }
            else {
                lections[pos] = -2;
            }
        }
    }

    vector<int>output;

    for (int i = 0; i < lections.size(); i++) {
        if (lections[i] >= 0) {
            output.push_back(lections[i]);
        }
    }

    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
