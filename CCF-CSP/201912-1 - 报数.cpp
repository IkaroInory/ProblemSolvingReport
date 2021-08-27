#include <iostream>
#include <vector>

using namespace std;

bool isSkip(int num) {
    if (num % 7 == 0) return true;

    while (num) {
        if (num % 10 == 7) return true;
        num /= 10;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int location = 0;
    int count = 0;
    vector<int> p(4);
    for (int i = 1; count < n; i++) {
        if (isSkip(i)) {
            p[location % 4]++;
        }
        else {
            count++;
        }
        location++;
    }

    auto begin = p.begin();
    while (begin < p.end()) {
        cout << *begin++ << endl;
    }
    return 0;
}