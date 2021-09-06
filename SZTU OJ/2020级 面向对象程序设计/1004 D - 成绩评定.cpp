#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        float temp;
        cin >> temp;

        char mark = 0;
        if (temp >= 85) mark = 'A';
        else if (temp >= 75) mark = 'B';
        else if (temp >= 65) mark = 'C';
        else if (temp >= 60) mark = 'D';
        else mark = 'F';

        cout << mark << endl;
    }
    return 0;
}