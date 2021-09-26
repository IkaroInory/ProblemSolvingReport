#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int allScholarship = 0;

struct student {
    string name;
    int averageMark;
    int evaluationMark;
    bool isCadre;
    bool isWestern;
    int paper;
    int scholarship;
    student() {
        name = "";
        averageMark = 0;
        evaluationMark = 0;
        isCadre = false;
        isWestern = false;
        paper = 0;
        getScholarship();
    }
    student(string _name,int _am, int _em, char _cadre, char _western, int _paper) {
        name = _name;
        averageMark = _am;
        evaluationMark = _em;
        isCadre = _cadre == 'Y';
        isWestern = _western == 'Y';
        paper = _paper;
        getScholarship();
    }
    int getScholarship() {
        int res = 0;
        if (averageMark > 80 && paper >= 1) res += 8000;
        if (averageMark > 85 && evaluationMark > 80) res += 4000;
        if (averageMark > 90) res += 2000;
        if (averageMark > 85 && isWestern) res += 1000;
        if (evaluationMark > 80 && isCadre) res += 850;
        scholarship = res;
        allScholarship += res;
        return res;
    }
};

bool cmp(student a, student b) {
    return a.scholarship > b.scholarship;
}

int main() {
    int n;
    cin >> n;
    vector<student> v(n);
    for (int i = 0; i < n; i++) {
        string _name;
        int _am, _em, _paper;
        char _cadre, _western;
        cin >> _name >> _am >> _em >> _cadre >> _western >> _paper;
        v[i] = { _name,_am,_em ,_cadre ,_western ,_paper };
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[0].name << endl
        << v[0].scholarship << endl
        << allScholarship << endl;

    return 0;
}