#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <bitset>
using namespace std;

int ep[8] = { 4, 1, 2, 3, 2, 3, 4, 1 };
int ip[8] = { 2, 6, 3, 1, 4, 8, 5, 7 };
int ipt[8] = { 4, 1, 3, 5, 7, 2, 8, 6 };

int p4[4] = { 2, 4, 3, 1 };
int p8[8] = { 6, 3, 7, 4, 8, 5, 10, 9 };
int p10[10] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };

int s0[4][4] = { {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2} };
int s1[4][4] = { {0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3} };

class bit {
    string b;
public:
    bit() : bit("0") {}
    bit(string s) : b(s) {}

    bit operator^(bit v) {
        const int len = this->b.length();
        string s = "";
        for (int i = 0; i < len; i++) {
            int l = b[i] - '0';
            int r = v.b[i] - '0';
            s += '0' + l ^ r;
        }
        return bit(s);
    }
    void operator^=(bit v) {
        const int len = this->b.length();
        string s = "";
        for (int i = 0; i < len; i++) {
            int l = b[i] - '0';
            int r = v.b[i] - '0';
            s += '0' + l ^ r;
        }
        this->b = s;
    }
    bit operator<<(const int v) {
        string s = b.substr(v, b.length() - v);
        for (int i = 0; i < v; i++)
            s += '0';
        return bit(s);
    }
    bit operator>>(const int v) {
        string s = "";
        for (int i = 0; i < v; i++)
            s += '0';
        s += b.substr(0, b.length() - v);
    }

    int toInt() {
        bitset<2> tmp(b);
        return (int)tmp.to_ulong();
    }
    bit getPermutation(const int box[], int len) {
        string s = "";
        for (int i = 0; i < len; i++) {
            s += b[box[i] - 1];
        }
        return bit(s);
    }
    bit getExtension(const int box[], int len) {
        string s = "";
        for (int i = 0; i < len; i++) {
            s += b[box[i] - 1];
        }
        return bit(s);
    }
    bit getCompress(int box[4][4]) {
        string r_s = b.substr(0, 1) + b.substr(b.length() - 1, 1);
        string c_s = b.substr(1, b.length() - 2);
        int r = bit(r_s).toInt();
        int c = bit(c_s).toInt();
        bitset<2> res(box[r][c]);
        return bit(res.to_string());
    }

    void permutation(const int box[], int len) {
        string s = "";
        for (int i = 0; i < len; i++) {
            s += b[box[i] - 1];
        }
        b = s;
    }
    void rotateLeft(int n) {
        b = b.substr(n, b.length() - n) + b.substr(0, n);
    }

    vector<bit> split(int len) {
        vector<bit> res;
        res.emplace_back(bit(b.substr(0, len)));
        res.emplace_back(bit(b.substr(len, b.length() - len)));
        return res;
    }
    string toString() {
        return b;
    }

    static bit merge(bit b1, bit b2) {
        return bit(b1.b + b2.b);
    }
    static bit getBit2(int n) {
        bitset<2> tmp(n);
        return bit(tmp.to_string());
    }
};

vector<bit> getKey(bit key) {
    vector<bit> res;
    bit kp = key.getPermutation(p10, 10);
    bit lk = kp.split(5)[0];
    bit rk = kp.split(5)[1];

    lk.rotateLeft(1);
    rk.rotateLeft(1);
    bit k1 = bit::merge(lk, rk);
    k1.permutation(p8, 8);
    res.emplace_back(k1);
    lk.rotateLeft(2);
    rk.rotateLeft(2);
    bit k2 = bit::merge(lk, rk);
    k2.permutation(p8, 8);
    res.emplace_back(k2);

    return res;
}

int main()
{
    bit b("00010110");
    bit key("0111111101");
    vector<bit> k = getKey(key);

    cout << "Message:\t" << b.toString() << endl;

    b.permutation(ip, 8);
    for (int i = 0; i < 2; i++) {
        bit lm = b.split(4)[0];
        bit rm = b.split(4)[1];
        bit rmc = b.split(4)[1];
        bit rme = rm.getExtension(ep, 8);
        rme ^= k[i];
        bit lrme = rme.split(4)[0];
        bit rrme = rme.split(4)[1];
        rme = bit::merge(lrme.getCompress(s0), rrme.getCompress(s1));
        rme.permutation(p4, 4);

        bit lme = rme ^ lm;
        b = bit::merge(lme, rmc);
    }
    b.permutation(ipt, 8);

    cout << "Encryption:\t" << b.toString() << endl;

    b.permutation(ip, 8);
    for (int i = 0; i < 2; i++) {
        bit lm = b.split(4)[0];
        bit rm = b.split(4)[1];
        bit rmc = b.split(4)[1];
        bit rme = rm.getExtension(ep, 8);
        rme ^= k[2 - i - 1];
        bit lrme = rme.split(4)[0];
        bit rrme = rme.split(4)[1];
        rme = bit::merge(lrme.getCompress(s0), rrme.getCompress(s1));
        rme.permutation(p4, 4);

        bit lme = rme ^ lm;
        b = bit::merge(lme, rmc);
    }
    b.permutation(ipt, 8);
    cout << "Decryption:\t" << b.toString() << endl;
    return 0;
}