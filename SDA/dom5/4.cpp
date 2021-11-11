#include<iostream>
#include<vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int>players;
    players.reserve(n);

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        players.push_back(tmp);
    }

    int to_final = 0;

    int i_stored = 0;
    bool i_is_stored = false;
    int end;
    int new_end = 0;

    bool first = true;

    while (true) {

        vector<int>prev_players = players;

        end = new_end;

        if (first) {
            end = prev_players.size() - 1;
            first = false;
        }

        int ppl_eliminated = 0;

        i_is_stored = false;


        for (int i = i_stored; i < end; i++) {
            if (i + 1 < prev_players.size() && prev_players[i] < prev_players[i + 1]) {
                if (i_is_stored == false)i_stored = i;
                i_is_stored = true;
                new_end = i - ppl_eliminated + 1;
                players.erase(players.begin() + (i - ppl_eliminated) + 1);
                ppl_eliminated++;
            }

        }

        if (ppl_eliminated == 0) {
            break;
        }

        to_final++;
    }

    std::cout << to_final;

    return 0;
}

//int main() {
//    int n;
//    cin >> n;
//
//    vector<int>players;
//
//    for (int i = 1; i <= n; i++) {
//        int tmp;
//        cin >> tmp;
//        players.push_back(tmp);
//    }
//
//    int to_final = 0;
//
//    while (true) {
//
//        int ppl_eliminated = 0;
//
//        int tmp;
//
//        bool is_tmp = false;
//
//
//        for (int i = 0; i < players.size() - 1; i++) {
//            if (is_tmp) {
//                if (tmp < players[i+1]) {
//                    tmp = players[i+1];
//                    players.erase(players.begin() + i + 1);
//                    ppl_eliminated++;
//                    i--;
//                }
//                else is_tmp = false;
//            }
//            else if (players[i] < players[i + 1]) {
//                tmp = players[i + 1];
//                is_tmp = true;
//                players.erase(players.begin() + i + 1);
//                ppl_eliminated++;
//                i--;
//
//            }
//        }
//
//        if (ppl_eliminated == 0) {
//            break;
//        }
//
//        to_final++;
//    }
//
//    cout << to_final;
//
//    return 0;
//}
