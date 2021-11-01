#include <iostream>

using namespace std;

int COUNT = 0;

class robot {
protected:
    string name;
    int hp = 0;
    int damage = 0;
    int defensive = 0;
    int level = 0;
    char type = 'N';
public:
    robot(string name_) : name(name_) {}

    string getName() { return name; }
    int getLv() { return level; }
    char getType() { return type; }
    void print() {
        cout << name << "--"
            << type << "--"
            << level << "--"
            << hp << "--"
            << damage << "--"
            << defensive << endl;
    }
};
class typeN : public robot {
public:
    typeN(string name_, int level_) : robot(name_) {
        type = 'N';
        level = level_;
        hp = 5 * level_;
        damage = 5 * level_;
        defensive = 5 * level_;
    }
};
class typeA : public robot {
public:
    typeA(string name_, int level_) : robot(name_) {
        type = 'A';
        level = level_;
        hp = 5 * level_;
        damage = 10 * level_;
        defensive = 5 * level_;
    }
};
class typeD : public robot {
public:
    typeD(string name_, int level_) :robot(name_) {
        type = 'D';
        level = level_;
        hp = 5 * level_;
        damage = 5 * level_;
        defensive = 10 * level_;
    }
};
class typeH : public robot {
public:
    typeH(string name_, int level_) :robot(name_) {
        type = 'H';
        level = level_;
        hp = 50 * level_;
        damage = 5 * level_;
        defensive = 5 * level_;
    }
};

robot* update(robot* r, char newType) {
    if (r->getType() != newType) {
        string name = r->getName();
        int level = r->getLv();
        robot* tmp = nullptr;
        switch (newType) {
        case 'N':
            tmp = new typeN(name, level);
            break;
        case 'A':
            tmp = new typeA(name, level);
            break;
        case 'D':
            tmp = new typeD(name, level);
            break;
        case 'H':
            tmp = new typeH(name, level);
            break;
        }
        COUNT++;
        return tmp;
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string name;
        char type;
        int level;
        char newType;
        cin >> name >> type >> level
            >> newType;

        robot* tmp = nullptr;
        switch (type) {
        case 'N':
            tmp = new typeN(name, level);
            break;
        case 'A':
            tmp = new typeA(name, level);
            break;
        case 'D':
            tmp = new typeD(name, level);
            break;
        case 'H':
            tmp = new typeH(name, level);
            break;
        }

        update(tmp, newType)->print();
    }

    cout << "The number of robot transform is " << COUNT << endl;

    return 0;
}