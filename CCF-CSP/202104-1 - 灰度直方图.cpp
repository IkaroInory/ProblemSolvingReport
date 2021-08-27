#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, L;
    cin >> n >> m >> L;

    vector<int> graph(L);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            graph[temp]++;
        }
    }
    
    auto begin = graph.begin();
    while (begin < graph.end()) {
        cout << *begin++ << " ";
    }

    return 0;
}