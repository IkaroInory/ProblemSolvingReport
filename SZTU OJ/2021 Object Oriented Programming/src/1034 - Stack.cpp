//
//
// Author   IkaroInory
// Date     2021/10/11
//
// All the code of this course and submitted on Online Judge is open source on Github.
// Welcome to reference and verification.
//
// Online Judge
// http://10.11.219.17/JudgeOnline/
// Github Repository
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2021%20Object%20Oriented%20Programming
//
//

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CStack {
private:
    int* a;
    int size;
    int top;
public:
    CStack();
    CStack(int s);
    CStack(CStack& r_s);
    ~CStack();
    int get(int index);
    void push(int n);
    int isEmpty();
    int isFull();
    int pop();
};

CStack::CStack() {
    a = new int[10];
    size = 10;
    top = 0;
    cout << "Constructor." << endl;
}
CStack::CStack(int s) {
    a = new int[s];
    size = s;
    top = 0;
    cout << "Constructor." << endl;
}
CStack::CStack(CStack& r_s) {
    a = new int[r_s.size];
    for (int i = 0; i < r_s.top; i++) {
        a[i] = r_s.a[i];
    }
}
CStack::~CStack() {
    delete[] a;
    cout << "Destructor." << endl;
}
int CStack::get(int index) {
    return a[index];
}
void CStack::push(int n) {
    if (top < size) a[top++] = n;
}
int CStack::isEmpty() {
    return top == 0;
}
int CStack::isFull() {
    return top == size;
}
int CStack::pop() {
    return a[--top];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        CStack s(n);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            s.push(temp);
        }
        while (n--) {
            cout << s.pop() << " ";
        }
        cout << endl;
    }
    return 0;
}