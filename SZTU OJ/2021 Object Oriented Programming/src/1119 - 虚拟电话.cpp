#include <iostream>

using namespace std;

class phone {
private:
    int num;
    char t;
    int s;
    string name;
public:
    phone(int num_, char t_, int s_, string name_) : num(num_), t(t_), s(s_), name(name_) {
        cout << num_ << " constructed." << endl;
    }
    ~phone() {
        cout << num << " destructed. " << endl;
    }

    bool find(int num_) {
        return num_ == num;
    }
    void print() {
        string state = s ? "use" : "unuse";
        cout << "Phone=" << num << "--"
            << "Type=" << t << "--"
            << "State=" << state << "--"
            << "Owner=" << name << endl;
    }
};

int main() {
    int num[3];
    char type[3];
    int s[3];
    string name[3];
    for (int i = 0; i < 3; i++) cin >> num[i] >> type[i] >> s[i] >> name[i];
    int t;
    cin >> t;
    int* find = new int[t];
    for (int i = 0; i < t; i++) cin >> find[i];

    phone p1(num[0], type[0], s[0], name[0]);
    phone p2(num[1], type[1], s[1], name[1]);
    phone p3(num[2], type[2], s[2], name[2]);

    for (int i = 0; i < t; i++) {
        if (p1.find(find[i])) p1.print();
        else if (p2.find(find[i])) p2.print();
        else if (p3.find(find[i])) p3.print();
        else cout << "wrong number." << endl;
    }
    return 0;
}