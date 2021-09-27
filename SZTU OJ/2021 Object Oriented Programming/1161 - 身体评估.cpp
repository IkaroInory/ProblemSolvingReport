//
//
// Author   IkaroInory
// Date     2021/9/27
//
// All the code of this course and submitted on Online Judge is open source on Github.
// Welcome to reference and verification.
//
// Online Judge
// http://10.11.219.17/JudgeOnline/
// Github Repository
// https://github.com/IkaroInory/ProblemSolvingReport/tree/master/SZTU%20OJ/2020%20Object%20Oriented%20Programming
//
//

#include <iostream>
#include <iomanip>

using namespace std;

class human {
    private:
        string name;
        float heigth;
        float weigth;
        float waist;
    public:
        human() {
            name = "<name>";
            heigth = 0;
            weigth = 0;
            waist = 0;
        }
        human(string _n, float _h, float _w, float _wa) {
            name = _n;
            heigth = _h;
            weigth = _w;
            waist = _wa;
        }
        float getBMI() {
            return weigth / heigth / heigth;
        }
        float getBFR() {
            float a = waist * 0.74;
            float b = weigth * 0.082 + 34.89;
            return (a - b) / weigth;
        }
        void print() {
            cout << fixed << setprecision(0)
                << name << "的BMI指数为" << getBMI() 
                << fixed << setprecision(2)
                << "--体脂率为" << getBFR() << endl;
        }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string _n;
        float _h, _w, _wa;
        cin >> _n >> _h >> _w >> _wa;

        human temp = { _n, _h, _w, _wa };
        temp.print();
    }
    return 0;
}