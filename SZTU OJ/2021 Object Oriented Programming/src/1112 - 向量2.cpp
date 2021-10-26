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
    CVector(const CVector& vector) {
        n = vector.n;
        date = new int[n];
        for (int i = 0; i < n; i++) date[i] = vector.date[i];
    }
    ~CVector() { delete date; }

    friend CVector Add(const CVector V1, const CVector V2) {
        CVector sum(V1);
        for (int i = 0; i < V1.n; i++) sum.date[i] += V2.date[i];
        return sum;
    }

    void print() {
        for (int i = 0; i < n; i++) cout << date[i] << ' ';
        cout << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* list1 = new int[n];
        int* list2 = new int[n];
        for (int i = 0; i < n; i++) cin >> list1[i];
        for (int i = 0; i < n; i++) cin >> list2[i];

        CVector v1(n, list1), v2(n, list2);
        v1.print();
        v2.print();
        Add(v1, v2).print();

        delete[] list1, list2;

    }
    return 0;
}