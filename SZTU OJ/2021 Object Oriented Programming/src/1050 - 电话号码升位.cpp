#include <iostream>

using namespace std;

class CTelNumber {
private:
    string num;
public:
    CTelNumber(string _num) : num(_num) {}
    CTelNumber(const CTelNumber& _CTelNumber) {
        num = _CTelNumber.num;
        if (_CTelNumber.num.length() < 7) {
            cout << "Illegal phone number" << endl;
            return;
        }
        for (int i = 0; i < num.length(); i++) {
            if (!(num[i] >= '0' && num[i] <= '9')) {
                cout << "Illegal phone number" << endl;
                return;
            }
        }

        if (num[0] - '0' > 1 && num[0] - '0' < 5) {
            num = '8' + num;
        }
        else if (num[1] - '0' > 4 && num[1] - '0' < 9) {
            num = '2' + num;
        }
        else {
            cout << "Illegal phone number" << endl;
            return;
        }
        cout << num << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string num;
        cin >> num;
        CTelNumber temp1(num);
        CTelNumber temp2(temp1);
    }
    return 0;
}