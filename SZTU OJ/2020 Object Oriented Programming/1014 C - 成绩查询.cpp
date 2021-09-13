//
// All my codes are open source to Github.
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2020%20Object%20Oriented%20Programming
//

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* mark = new int[n];
        for (int i = 0; i < n; i++)
            cin >> mark[i];
        
        int* mid = mark + n / 2;

        int search;
        cin >> search;
        cout << *(mid - 1) << " " << *(mid + 1) << endl;
        cout << *(mid - n / 2 + search - 1) << endl;
    }
    return 0;
}