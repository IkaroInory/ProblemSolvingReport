#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        char* p1, * p2, * p3;
        int l[3][2];
        cin >> s1 >> s2 >> s3;

        for (int i = 0; i < 3; i++) {
            cin >> l[i][0] >> l[i][1];
        }
        string str1 = s1.substr(l[0][0] - 1, l[0][1] - l[0][0] + 1);
        string str2 = s2.substr(l[1][0] - 1, l[1][1] - l[1][0] + 1);
        string str3 = s3.substr(l[2][0] - 1, l[2][1] - l[2][0] + 1);

        cout << str1 << str2 << str3 << endl;

    }
    return 0;
}