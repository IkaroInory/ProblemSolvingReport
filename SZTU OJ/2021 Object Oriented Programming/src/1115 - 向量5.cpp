#include <iostream>
#include <iomanip>

using namespace std;
class CMatrix;

class CVector {
private:
    int* date;
    int n;
    int sum = 0;
public:
    CVector() {
        n = 5;
        date = new int[n];
        for (int i = 0; i < n; i++) {
            date[i] = i;
            sum += i;
        }
    }
    CVector(int _n, int element) {
        n = _n;
        date = new int[n];
        for (int i = 0; i < n; i++) {
            date[i] = element;
            sum += element;
        }
    }
    CVector(int _n, int* elements) {
        n = _n;
        date = new int[n];
        for (int i = 0; i < n; i++) {
            date[i] = elements[i];
            sum += elements[i];
        }
    }
    CVector(const CVector& vector) {
        n = vector.n;
        date = new int[n];
        for (int i = 0; i < n; i++) {
            date[i] = vector.date[i];
            sum += vector.date[i];
        }
    }
    ~CVector() { delete date; }

    friend class CMatrix;
    friend CVector Add(const CVector V1, const CVector V2) {
        CVector sum(V1);
        for (int i = 0; i < V1.n; i++) sum.date[i] += V2.date[i];
        return sum;
    }

    int getLength() { return n; }
    int getSum() { return sum; }
    void print() {
        for (int i = 0; i < n; i++) cout << date[i] << ' ';
    }
};

class CStudent {
private:
    string name;
    CVector* score;
public:
    CStudent() {
        name = "<name>";
    }
    CStudent(string _name, int _n, int* _list) {
        name = _name;
        score = new CVector(_n, _list);
    }
    ~CStudent() { delete score; }

    void print() {
        cout << name << ' ';
        score->print();
        cout << fixed << setprecision(2)
            << (double)score->getSum() / (double)score->getLength() << endl;
    }
};

class CMatrix {
private:
    int n;
    int** data;
public:
    CMatrix(int _n, int** _data) {
        n = _n;
        data = _data;
    }
    ~CMatrix() { delete data; }
    bool isTimes(const CVector& v) {
        return n == v.n;
    }
    CVector Multi(const CVector& v) {

    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int** data = new int* [n];
        for (int i = 0; i < n; i++) data[i] = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> data[i][j];
        int m;
        cin >> m;
        int* v = new int[m];
        for (int i = 0; i < m; i++) cin >> v[i];

        if (n != m) cout << "error" << endl;
        else {
            int* ans = new int[n];
            for (int i = 0; i < n; i++)
                ans[i] = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    ans[i] += data[i][j] * v[j];
            for (int i = 0; i < n; i++)
                cout << ans[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}