//#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<utility>
using namespace std;




int main() {

    int n, m, t;

    cin >> n >> m;

    set<int>output;

    int k;
    cin >> t >> k;
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        int tmp = (row - 1) * m + col;



        for (int s = 0; s <= t; s++) {

            int up, down;
            up = tmp - m * s;
            down = tmp + m * s;

            if (up > 0 && up <= m * n)output.insert(up);
            if (down > 0 && down <= m * n)output.insert(down);

            for (int p = 1; p <= s; p++) {
                int left_u, right_u, left_d, right_d;

                pair<int, int>up_restrictions{(row-s+p-1)*m+1,(row - s + p) * m };
                pair<int, int>down_restrictions{(row+s-p-1)*m+1,(row + s - p) * m };

                left_u = up + m*p - p;
                right_u = up + m*p + p;
                left_d = down - m*p - p;
                right_d = down - m*p + p;

                if (left_u > 0 && left_u <= m * n 
                    && left_u >= up_restrictions.first) output.insert(left_u);
                if (right_u > 0 && right_u <= m * n 
                    && right_u <= up_restrictions.second) output.insert(right_u);
                if (left_d > 0 && left_d <= m * n 
                    && left_d >= down_restrictions.first) output.insert(left_d);
                if (right_d > 0 && right_d <= m * n 
                    && right_d <= down_restrictions.second) output.insert(right_d);
            }

        }

    }

    std::cout << m*n - output.size();

    return 0;
}
