#include <iostream>

using namespace std;

class Hotel {
private:
    static int m_TotalCustNum;
    static float m_TotalEearning;

    string m_CustomerName;
    int m_CustomerID;
public:
    static float m_Rent;

    Hotel(string a_Customer) : m_CustomerName(a_Customer), m_CustomerID(m_TotalCustNum++ + 1) {
        m_TotalEearning += m_Rent;
    }

    void Display() {
        cout << m_CustomerName << ' ';
        printf("2015%04d ", m_CustomerID);
        cout << m_TotalCustNum << ' '
            << m_TotalEearning << endl;
    }
};

int Hotel::m_TotalCustNum = 0;
float Hotel::m_TotalEearning = 0;
float Hotel::m_Rent = 0;

int main() {
    float rent;
    cin >> rent;
    Hotel::m_Rent = rent;

    string name;
    while (cin >> name && name != "0") {
        Hotel h(name);
        h.Display();
    }
    return 0;
};