#include <iostream>

using namespace std;

class ct {
private:
    int value;
public:
    ct() : value(0) {
        cout << "Constructed by default, value = 0" << endl;
    }
    ct(int _v) : value(_v) {
        cout << "Constructed using one argument constructor, value = " << _v << endl;
    }
    ct(const ct& _ct) {
        value = _ct.value;
        cout << "Constructed using copy constructor, value = " << _ct.value << endl;
    }

    int getValue() {
        return value;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int count;
        cin >> count;
        if (count == 0) {
            ct temp;
        }
        else {
            int num;
            cin >> num;
            ct temp1(num);
            while (--count) {
                ct temp2(temp1);
                temp1 = temp2;
            }
        }
    }
    return 0;
}