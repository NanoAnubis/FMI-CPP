#include<iostream>
//#include<list>
#include<vector>
using namespace std;

//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>

struct Node {

    int pos;
    int data;
    Node* next;
    Node* prev;

    Node() {
        pos = 0;
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int _pos,int _data) {
        pos = _pos;
        data = _data;
        next = nullptr;
        prev = nullptr;
    }

};

class List {

public:

    List() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }


    int size() {
        return _size;
    }


    void push_back(int pos,int num, vector<Node*>& position) {
        _size++;

        if (head == nullptr) {
            head = new Node(pos, num);
            tail = head;
            position.push_back(head);
            return;
        }

        tail->next = new Node(pos, num);
        tail->next->prev = tail;
        tail = tail->next;
        position.push_back(tail);

    }



    Node* head;
    Node* tail;
    int _size;
private:


};


int colide(Node* left, Node* right, List& balls) {

    if (balls.size() <= 0)return 0;

    int counter = 0;

    if (left != nullptr && right != nullptr && left->data == right->data) {
        
        int c = left->data;

        counter = 2;

        left = left->prev;
        right = right->next;

        while (left != nullptr && left->data == c) {
            counter++;
            left=left->prev;
        }
        while (right != nullptr && right->data == c) {
            counter++;
            right=right->next;
        }

        if (counter >= 3) {


            balls._size -= counter;

            if (left != nullptr)left->next = right;
            else if (right != nullptr) balls.head = right;

            if (right != nullptr)right->prev = left;
            else balls.tail = left;

            if (balls.size() <= 0) return counter;

            counter += colide(left, right, balls);
        }
        else counter = 0;
    }

    return counter;
}


int shoot(int p, int c, List& balls, vector<Node*>& positions) {

    if (balls.size() <= 0)return -1;

    Node* left = nullptr;
    Node* right = nullptr;
    int counter = 1;

    if (p < 0 || p >= positions.size()) return -2;

    if (positions[p] != nullptr) {
        left = positions[p];
        right = positions[p]->next;
    }

    while (left != nullptr && left->data == c) {
        counter++;
        left = left->prev;
    }
    while (right != nullptr && right->data == c) {
        counter++;
        right = right->next;
    }

    balls._size++;

    if (counter >= 3) {

        balls._size -= counter;
        
        if (balls.size() <= 0) return counter;

        if(left!=nullptr) left->next = right;
        else balls.head = right;

        if (right != nullptr) right->prev = left;
        else balls.tail = left;

        counter += colide(left, right, balls);

    }
    else {
        counter = 0;

        Node* new_ball = new Node(-1, c);
        if (positions[p] != nullptr) new_ball->next = positions[p]->next;
        new_ball->prev = positions[p];
        if (positions[p] != nullptr) positions[p]->next = new_ball;
        if (new_ball->next != nullptr) new_ball->next->prev = new_ball;

        positions.push_back(new_ball);
    }

    return counter;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    List balls;
    vector<Node*>positions;
    vector<int>output;

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        balls.push_back(i,tmp, positions);
    }

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int p, c;
        cin >> p >> c;

        output.push_back(shoot(p, c, balls, positions));
    
    }

    for (int i : output) {
        if (i == -1) {
            cout << "Game Over\n";
        }
        else {
            cout << i << '\n';
        }
    }

    if (balls.size() == 0) cout << "-1";
    else {
        Node* tmp = balls.head;

        while (tmp != nullptr) {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }

    }

    for (Node* i : positions) {
        delete i;
    }

    return 0;
}
