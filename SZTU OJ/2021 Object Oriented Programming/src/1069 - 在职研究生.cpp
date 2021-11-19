#include <iostream>

using namespace std;

class people {
protected:
    string name;
    char sex;
    int age;
public:
    people() : name(""), sex('m'), age(0) {}
    people(string name, char sex, int age) : name(name), sex(sex), age(age) {}

    virtual void display() {
        cout << "People:" << endl
            << "Name: " << name << endl
            << "Sex: " << sex << endl
            << "Age: " << age << endl;
    }
};
class student : virtual public people {
protected:
    string num;
    double score;
public:
    student(string name, char sex, int age, string num, double score) :
        people(name, sex, age), num(num), score(score) {}

    virtual void display() {
        cout << "Student:" << endl
            << "Name: " << name << endl
            << "Sex: " << sex << endl
            << "Age: " << age << endl
            << "No.: " << num << endl
            << "Score: " << score << endl;
    }
};
class teacher : virtual public people {
protected:
    string position;
    string department;
public:
    teacher(string name, char sex, int age, string position, string department) :
        people(name, sex, age), position(position), department(department) {}

    virtual void display() {
        cout << "Teacher:" << endl
            << "Name: " << name << endl
            << "Sex: " << sex << endl
            << "Age: " << age << endl
            << "Position: " << position << endl
            << "Department: " << department << endl;
    }
};
class gradOnWork : public student, public teacher {
    string direction;
    string tutor;
public:
    gradOnWork(
        string name,
        char sex,
        int age,
        string num,
        double score,
        string position,
        string department,
        string direction,
        string tutor
    ) :
        people(name,sex,age),
        student(name, sex, age, num, score), teacher(name, sex, age, position, department),
        direction(direction),
        tutor(tutor) {}

    virtual void display() {
        cout << "GradOnWork:" << endl
            << "Name: " << name << endl
            << "Sex: " << sex << endl
            << "Age: " << age << endl
            << "No.: " << num << endl
            << "Score: " << score << endl
            << "Position: " << position << endl
            << "Department: " << department << endl
            << "Direction: " << direction << endl
            << "Tutor: " << tutor << endl;
    }
};


int main() {
    string name, num, position, department, direction, tutor;
    double score;
    char sex;
    int age;
    cin >> name >> sex >> age;

    people* temp = new people(name, sex, age);
    temp->display();
    cout << endl;
    cin >> num >> score;
    temp = new student(name, sex, age, num, score);
    temp->display();
    cout << endl;
    cin >> position >> department;
    temp = new teacher(name, sex, age, position, department);
    temp->display();
    cout << endl;
    cin >> direction >> tutor;
    temp = new gradOnWork(name, sex, age, num, score, position, department, direction, tutor);
    temp->display();
    cout << endl;

    delete temp;
    return 0;
}