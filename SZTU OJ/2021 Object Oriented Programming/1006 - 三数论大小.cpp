#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int* pa = &a;
        int* pb = &b;
        int* pc = &c;
        if (*pa < *pb) {
            int temp = *pa;
            *pa = *pb;
            *pb = temp;
        }
        if (*pa < *pc) {
            int temp = *pa;
            *pa = *pc;
            *pc = temp;
        }
        if (*pb < *pc) {
            int temp = *pb;
            *pb = *pc;
            *pc = temp;
        }

        cout << *pa << " " << *pb << " " << *pc << endl;
    }
    return 0;
}