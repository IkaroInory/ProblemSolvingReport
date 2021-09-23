#include <iostream>

using namespace std;

int main() {
    int key;
    string pt;
    cin >> key >> pt;

    int len = pt.length();
    string ct = "";
    for (int i = 0; i < len; i++) {
        ct += (pt[i] - 'a' + key) % 26 + 'a';
    }

    cout << ct << endl;
    return 0;
}