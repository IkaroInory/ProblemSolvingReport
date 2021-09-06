#include <iostream>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        int l[3][2];
        int length = 0;
        cin >> s1 >> s2 >> s3;
        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
        
        for (int i = 0; i < 3; i++) {
            cin >> l[i][0] >> l[i][1];
            length += l[i][1] - l[i][0] + 1;
        }

        char* s = new char[length];

        int left = 0;
        for (int i = l[0][0] - 1; i < l[0][1]; i++) {
            *(s + left++) = s1[i];
        }
        for (int i = l[1][0] - 1; i < l[1][1]; i++) {
            *(s + left++) = s2[i];
        }
        for (int i = l[2][0] - 1; i < l[2][1]; i++) {
            *(s + left++) = s3[i];
        }
        
        cout << s << endl;
        
    }
    return 0;
}