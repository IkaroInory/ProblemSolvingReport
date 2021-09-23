#include <iostream>
#include <cmath>

using namespace std;

const int nodeCount = 4045;

int main() {
    int deepth = 0;
    while (pow(2, deepth) - 1 < nodeCount) deepth++;

    int lastUnconnectedFloorLeafNode = pow(2, deepth) - 1 - nodeCount;
    int lastFloorLeafNode = pow(2, deepth - 1) - lastUnconnectedFloorLeafNode;
    int connectedNode = lastFloorLeafNode % 2 == 0 ? lastFloorLeafNode / 2 : lastFloorLeafNode / 2 + 1;
    int unconnectedNode = pow(2, deepth - 1 - 1) - connectedNode;

    int res = lastFloorLeafNode + unconnectedNode;
    cout << res << endl;
    return 0;
}