#include <iostream>

using namespace std;

class vehicle {
protected:
    string no;
public:
    vehicle(string no) : no(no) {}

    virtual void display() = 0;
};
class car : public vehicle {
    int n, w;
public:
    car(string no, int n, int w) : vehicle(no), n(n), w(w) {}

    void display() {
        cout << no << " " << n * 8 + w * 2 << endl;
    }
};
class truck : public vehicle {
    int w;
public:
    truck(string no, int w) : vehicle(no), w(w) {}

    void display() {
        cout << no << " " << w * 5 << endl;
    }
};
class bus : public vehicle {
    int n;
public:
    bus(string no, int n) :vehicle(no), n(n) {}

    void display() {
        cout << no << " " << n * 3 << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int op;
        string no;
        cin >> op >> no;
        vehicle* temp = nullptr;
        if (op == 1) {
            int n, w;
            cin >> n >> w;
            temp = new car(no, n, w);
        }
        else if (op == 2) {
            int w;
            cin >> w;
            temp = new truck(no, w);
        }
        else if (op == 3) {
            int n;
            cin >> n;
            temp = new bus(no, n);
        }
        temp->display();

        delete temp;
    }
    return 0;
}