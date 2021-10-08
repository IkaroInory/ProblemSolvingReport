#include <iostream>

using namespace std;

 int main() {
     int n;
     cin >> n;
     int last = 0;
     int temp = 0;
     int maxSum = 0;
     int minSum = 0;
     for (int i = 0; i < n; i++) {
         cin >> temp;
         if (temp != last) minSum += temp;
         maxSum += temp;
         last = temp;
     }
     cout << maxSum << endl
         << minSum << endl;

     return 0;
}