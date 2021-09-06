#include <iostream>

using namespace std;

class co {
public:
    int x;
    int y;
    co() {
        x = 0;
        y = 0;
    }
    co(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

bool isIn(co ld, co ru, co point) {
    bool isX = point.x >= ld.x && point.x <= ru.x;
    bool isY = point.y >= ld.y && point.y <= ru.y;
    return isX && isY;
}

int main() {
    int n, k, t;
    co ld, ru;
    cin >> n >> k >> t >> ld.x >> ld.y >> ru.x >> ru.y;

    int _pass_ = 0;
    int _stay_ = 0;
    while (n--) {
        bool isPass = false;
        bool isStay = false;
        int stay = 0;
        for (int i = 0; i < t; i++) {
            co to;
            cin >> to.x >> to.y;

            if (isIn(ld, ru, to)) {
                stay++;
                isPass = true;
            }
            else stay = 0;

            if (stay >= k) isStay = true;
        }
        if (isPass) _pass_++;
        if (isStay) _stay_++;
    }

    cout << _pass_ << endl
        << _stay_ << endl;
    return 0;
}