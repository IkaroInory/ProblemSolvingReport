#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> tree(N);
    vector<int> apple(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            tree[i] += temp;
            apple[i] -= temp;
        }
    }

    int T = 0;
    for (int i = 0; i < N; i++) {
        T += tree[i];
    }
    int k = max_element(apple.begin(), apple.end()) - apple.begin() + 1;
    int P = apple[k - 1];
    cout << T << ' ' << k << ' ' << P << endl;
    return 0;
}