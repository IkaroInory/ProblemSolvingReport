#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const float usd = 6.2619;
    const float eur = 6.6744;
    const float jpy = 0.0516;
    const float hkd = 0.8065;

    int t;
    cin >> t;
    while (t--) {
        char type;
        float amount;
        cin >> type >> amount;

        const float* p = nullptr;
        float ans = 0;
        switch (type) {
            case 'D':
                p = &usd;
                break;
            case 'E':
                p = &eur;
                break;
            case 'Y':
                p = &jpy;
                break;
            case 'H':
                p = &hkd;
                break;
        }

        cout << fixed << setprecision(4) << *p * amount << endl;
    }
    return 0;
}