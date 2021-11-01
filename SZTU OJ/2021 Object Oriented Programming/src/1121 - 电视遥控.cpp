#include <iostream>

using namespace std;

class tv {
private:
    static int tvnum;
    static int dvdnum;

    int mode;
    int cn = 0;
    int voice;
public:
    tv() {
        mode = 1;
        voice = 50;
        tvnum++;
    }

    static int GetTVCount() { return tvnum; }
    static int GetDVDCount() { return dvdnum; }
    friend void op(tv& t, int mode, int voice, int cn);

    void print() {
        string mode_str = mode == 1 ? "TV模式" : "DVD模式";
        cout << mode_str << "--"
            << "频道" << cn << "--"
            << "音量" << voice << endl;
    }
};

int tv::tvnum = 0;
int tv::dvdnum = 0;


void op(tv& t, int mode, int voice, int cn) {
    if (t.mode != mode) {
        t.mode = mode;
        if (mode == 2) {
            t.cn = 99;
            tv::dvdnum++;
            tv::tvnum--;
        }
        else {
            t.cn = cn;
            tv::dvdnum--;
            tv::tvnum++;
        }
    }
    else {
        if (mode == 2) t.cn = 99;
        else t.cn = cn;
    }
    t.voice += voice;
    if (t.voice < 0) t.voice = 0;
    if (t.voice > 100) t.voice = 100;
}

int main() {
    int n;
    cin >> n;
    tv* television = new tv[n];
    int t;
    cin >> t;
    while (t--) {
        int num_t, mode, cn, voice;
        cin >> num_t >> mode >> cn >> voice;
        op(television[num_t - 1], mode, voice, cn);
        cout << "第" << num_t << "号电视机--";
        television[num_t - 1].print();
    }
    cout << "播放电视的电视机数量为" << tv::GetTVCount() << endl
        << "播放DVD的电视机数量为" << tv::GetDVDCount() << endl;

    delete[] television;
    return 0;
}