#include<iostream>

using namespace std;

class CVector {
private:
    int* date;
    int n;
public:
    CVector() {
        n = 5;
        date = new int[n];
        for (int i = 0; i < n; i++) date[i] = i;
    }
    CVector(int _n, int element) {
        n = _n;
        date = new int[n];
        for (int i = 0; i < n; i++) date[i] = element;
    }
    CVector(int _n, int elements[]) {
        n = _n;
        date = new int[n];
        for (int i = 0; i < n; i++) date[i] = elements[i];
    }
    ~CVector() { delete date; }

    void print() {
        for (int i = 0; i < n; i++) cout << date[i] << ' ';
        cout << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    CVector v1;
    v1.print();
    int* p = new int[t];
    for (int i = 0;i < t;i++) cin >> p[i];
    CVector v2(t, p);
    v2.print();
    delete[] p;
    return 0;
}