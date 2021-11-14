#include <string>
#include <vector>
#include <bitset>

using namespace std;

const int SIZE = 2;
const int COUNT = 2;

vector<int> ep{ 4, 1, 2, 3, 2, 3, 4, 1 };
vector<int> ip{ 2, 6, 3, 1, 4, 8, 5, 7 };
vector<int> ipt{ 4, 1, 3, 5, 7, 2, 8, 6 };

vector<int> p4{ 2, 4, 3, 1 };
vector<int> p8{ 6, 3, 7, 4, 8, 5, 10, 9 };
vector<int> p10{ 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };

vector<vector<int>> s0{ {1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2} };
vector<vector<int>> s1{ {0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3} };

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
        return bit(s);
    }

    bit getCompress(vector<vector<int>> box) {
        int len = b.length();
        string sr = this->b.substr(0, 1) + this->b.substr(len - 1, 1);
        string sc = this->b.substr(1, len - 2);
        int r = bit(sr).toInt();
        int c = bit(sc).toInt();
        bitset<SIZE> res(box[r][c]);
        return bit(res.to_string());
    }
    bit getTransformation(const vector<int> box) {
        int size = box.size();
        int len = this->b.length();
        string s = "";
        for (int i = 0; i < size; i++)
            if (box[i] - 1 < len)
                s += this->b[box[i] - 1];
        return bit(s);
    }
    int toInt() {
        bitset<2> tmp(b);
        return (int)tmp.to_ulong();
    }
    string toString() {
        return b;
    }

    void compress(const vector<vector<int>> box) {
        int len = b.length();
        string sr = this->b.substr(0, 1) + this->b.substr(len - 1, 1);
        string sc = this->b.substr(1, len - 2);
        int r = bit(sr).toInt();
        int c = bit(sc).toInt();
        bitset<SIZE> res(box[r][c]);
        this->b = res.to_string();
    }
    void transformation(const vector<int> box) {
        int size = box.size();
        int len = this->b.length();
        string s = "";
        for (int i = 0; i < size; i++)
            if (box[i] - 1 < len)
                s += this->b[box[i] - 1];
        this->b = s;
    }
    void rotateLeft(int n) {
        int len = b.length();
        b = b.substr(n, len - n) + b.substr(0, n);
    }
    void rotateRight(int n) {
        int len = b.length();
        b = b.substr(len - n, n) + b.substr(0, len - n);
    }

    vector<bit> split(int len) {
        vector<bit> res{
            bit(b.substr(0, len)),
            bit(b.substr(len, b.length() - len))
        };
        return res;
    }

    static bit merge(bit b1, bit b2) {
        return bit(b1.b + b2.b);
    }
    static bit getBit(int n) {
        return bit(bitset<SIZE>(n).to_string());
    }
};

vector<bit> getKey(bit key) {
    vector<bit> res;

    bit k = key.getTransformation(p10);
    bit left = k.split(5)[0];
    bit right = k.split(5)[1];

    left.rotateLeft(1);
    right.rotateLeft(1);
    bit k1 = bit::merge(left, right);
    k1.transformation(p8);
    res.emplace_back(k1);

    left.rotateLeft(2);
    right.rotateLeft(2);
    bit k2 = bit::merge(left, right);
    k2.transformation(p8);
    res.emplace_back(k2);

    return res;
}

bit SimplifiedDES_Encryption(bit message, bit key) {
    vector<bit> k = getKey(key);

    bit m = message.getTransformation(ip);
    for (int i = 0; i < COUNT; i++) {
        if (i != 0) {
            bit left = m.split(4)[0];
            bit right = m.split(4)[1];
            m = bit::merge(right, left);
        }
        bit left = m.split(4)[0];
        bit right = m.split(4)[1];
        bit right_copy = m.split(4)[1];

        right.transformation(ep);
        right ^= k[i];

        bit l = right.split(4)[0].getCompress(s0);
        bit r = right.split(4)[1].getCompress(s1);

        right = bit::merge(l, r);
        right.transformation(p4);

        left ^= right;

        m = bit::merge(left, right_copy);
    }
    m.transformation(ipt);

    return m;
}
bit SimplifiedDES_Decryption(bit ciphertext, bit key) {
    vector<bit> k = getKey(key);

    bit c = ciphertext.getTransformation(ip);
    for (int i = 0; i < COUNT; i++) {
        if (i != 0) {
            bit left = c.split(4)[0];
            bit right = c.split(4)[1];
            c = bit::merge(right, left);
        }
        bit left = c.split(4)[0];
        bit right = c.split(4)[1];
        bit right_copy = c.split(4)[1];

        right.transformation(ep);
        right ^= k[COUNT - i - 1];

        bit l = right.split(4)[0].getCompress(s0);
        bit r = right.split(4)[1].getCompress(s1);

        right = bit::merge(l, r);
        right.transformation(p4);

        left ^= right;

        c = bit::merge(left, right_copy);
    }
    c.transformation(ipt);

    return c;
}