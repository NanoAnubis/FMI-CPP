#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




bool compare_pairs(pair<long, long> first, pair<long, long> second) {
    return (first.first < second.first && first.second < second.second);
}

long lis(vector<pair<long, long>>& arr) {
    long n = arr.size();
    vector<long> data(n, 1);
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
            if (compare_pairs(arr[j], arr[i]))
                data[i] = max(data[i], data[j] + 1);
        }
    }

    long ans = data[0];
    for (long i = 1; i < n; i++) {
        ans = max(ans, data[i]);
    }
    return ans;
}



int main() {

    long n;
    cin >> n;
    vector<pair<long, long>>demons;
    vector<vector<long>>demons1;


    for (long i = 1; i <= n; i++) {
        long def;
        long atk;
        cin >> def >> atk;
        pair<long, long>tmp{ def,atk };
        demons.push_back(tmp);

    }

    sort(demons.begin(), demons.end(), compare_pairs);
    cout << lis(demons) << endl;

    return 0;

}
