#include <iostream>

using namespace std;

int main() {
    int sd = 365 * 10 + 3 + 31 * 3 + 30 * 2 + 10 + 23;
    int b = sd / 35;
    int c = sd % 35;
    cout << b * 2 + 2 << endl;
    return 0;
}