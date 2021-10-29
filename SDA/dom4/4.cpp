#include<iostream>
#include<list>

using namespace std;


void milen(list<int>&notes, list<int>::iterator& ittor) {

    list<int>::iterator new_ittor = ittor;

    if (notes.size() % 2 == 0) {
        new_ittor = notes.begin();
    }
    else {
        new_ittor = (--notes.end());
    }

    notes.splice(notes.end(), notes, notes.begin(), ittor);

    ittor = new_ittor;

}

int main() {

    list<int> notes;

    int n;
    cin >> n;

    list<int>::iterator ittor;

    for (int i = 1; i <= n; i++) {
        string func;
        int num;
        cin >> func;

        if (func == "add") {
            cin >> num;
            notes.push_back(num);
            if (notes.size() == 1) {
                ittor = notes.begin();
            }
            else if (notes.size() % 2 == 0) {
                ittor++;
            }
        }
        else if (func == "gun") {

            if (notes.size() % 2 == 0 && notes.size() != 0) {
                ittor--;
            }

            if(notes.size()>0) notes.pop_back();

            
        }
        else if (func == "milen") {
            if(notes.size()>1) milen(notes,ittor);
        }
    }

    cout << notes.size() << '\n';

    for (int note : notes) {
        cout << note << " ";
    }


    return 0;
}