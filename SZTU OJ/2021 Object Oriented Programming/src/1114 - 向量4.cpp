#include <iostream>
#include <iomanip>

using namespace std;

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

int main()
{
    string name;
    while (cin >> name) {
        int n;
        cin >> n;
        int* list = new int[n];
        for (int i = 0; i < n; i++) cin >> list[i];
        CStudent student(name, n, list);
        student.print();
        delete[] list;
    }
    return 0;
}